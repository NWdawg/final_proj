# EEP 520 project
## Project: Click and push
## Overview:
Use 2 stick-like rectangulars to sweep the blocks to different side on the canvas. Click manually to reset the positions of the sticks, then let go and let the sticks to push to opposite directions.
## Key challenges:
1. How to reset the position and program the state machine according to our need. 

Used the concept of state machine learned in lecture8. Then utilized the built-in `watch` function to listen on the clicks on the screen. Finally update the behaviors in the state machine.

3. Control the moving direction of the 2 opposite sticks once clicked

Modified the state machine and the built-in `watch` function to make sure the sticks are moving to the opposite direction when clicked on the screen.

## Installation
Use `git clone` to get the code.

Run the docker container which has pre-loaded ENVIRO: `docker run -p80:80 -p8765:8765 -v $PWD:/source -it klavins/enviro:v1.61 bash`

Start the esm: `esm start`

Compile the code: `make`

## Run the project

Start the project: `enviro`

Open the browser and go to: `http://localhost`

Once the sticks finish the first go, use our judgment and click on the scree to relocate the sticks, so that the sticks can push the remaining blocks to opposite directions.

## Licence

[MIT Licence](https://opensource.org/licenses/MIT)

## Acknowledgements

Used [elma](https://github.com/klavinslab/elma) 

Used [enviro](https://github.com/klavinslab/enviro)
