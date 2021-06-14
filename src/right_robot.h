#ifndef __RIGHT_ROBOT_AGENT__H
#define __RIGHT_ROBOT_AGENT__H 

#include "enviro.h"

using namespace enviro;

class RightRobotController : public Process, public AgentInterface {

    public:
    RightRobotController() : Process(), AgentInterface() {}

    void init() {
        // Relocate the second robot and let it move towards another direction
        watch("screen_click", [&](Event &e) {
            teleport((e.value()["x"]), e.value()["y"], 0);
            move_toward(300, e.value()["y"],0);
        });
    }
    void start() {}
    void update() {
        // Let the first robot move towards another direction with a given speed
        track_velocity(12, 0);
        move_toward(-400, 50);
        watch("screen_click", [&](Event &e) {
            move_toward(300, e.value()["y"],0);
        });
    }
    void stop() {}

};

class RightRobot : public Agent {
    public:
    RightRobot(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    RightRobotController c;
};

DECLARE_INTERFACE(RightRobot)

#endif