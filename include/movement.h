#ifndef MOVEMENT_H_
#define MOVEMENT_H_
#include "hardwareSetup.h"
typedef enum direction
{
    FORWARD, BACKWARD, LEFT, RIGHT, TURN_LEFT, TURN_RIGHT
    }direction;

//function prototypes
extern void driveMove(direction direction, int speed);
extern void driveStop();
extern void driveMoveTo(direction direction, int speed,
                        sensor encoder, int count);
#endif //MOVEMENT_H_
