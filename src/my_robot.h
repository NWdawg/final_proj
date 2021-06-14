#ifndef __MY_ROBOT_AGENT__H
#define __MY_ROBOT_AGENT__H 

#include "enviro.h"

using namespace enviro;

class MyRobotController : public Process, public AgentInterface {

    public:
    MyRobotController() : Process(), AgentInterface() {}

    void init() {
        // Relocate the first robot and let it move towards one direction
        watch("screen_click", [&](Event &e) {
            teleport((e.value()["x"]), e.value()["y"], 0);
            move_toward(-300, e.value()["y"],0);
        });
    }
    void start() {}
    void update() {
        // Let the first robot move towards one direction with a given speed
        track_velocity(12, 0);
        move_toward(400, 50);
        watch("screen_click", [&](Event &e) {
            move_toward(-300, e.value()["y"],0);
        });
    }
    void stop() {}

};

class MyRobot : public Agent {
    public:
    MyRobot(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    MyRobotController c;
};

DECLARE_INTERFACE(MyRobot)

#endif