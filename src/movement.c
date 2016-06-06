//////////////////////////////////////////////////////////////////
//this file contains functions for moving the robot autonomously//
//////////////////////////////////////////////////////////////////
#include "main.h"
#include "hardwareSetup.h"

//enumeration for different movement directions
typedef enum direction
{
    FORWARD, BACKWARD, LEFT, RIGHT, TURN_LEFT, TURN_RIGHT
}direction;

//leave encoder port as  -1 to not use encoders for movement
void driveMove(direction direction, int speed)
{
    //one function for movement in all directions,
    //how this is done is self explainitory.
    switch(direction)
    {
    case FORWARD:
        setMotor(LFDrive, speed);
        setMotor(LBDrive, speed);
        setMotor(RFDrive, speed);
        setMotor(RBDrive, speed);
        break;

    case BACKWARD:
        setMotor(LFDrive, -speed);
        setMotor(LBDrive, -speed);
        setMotor(RFDrive, -speed);
        setMotor(RBDrive, -speed);
        break;

    case LEFT:
        setMotor(LFDrive, -speed);
        setMotor(LBDrive,  speed);
        setMotor(RFDrive,  speed);
        setMotor(RBDrive, -speed);
        break;

    case RIGHT:
        setMotor(LFDrive,  speed);
        setMotor(LBDrive, -speed);
        setMotor(RFDrive, -speed);
        setMotor(RBDrive,  speed);
        break;

    case TURN_LEFT:
        setMotor(LFDrive, -speed);
        setMotor(LBDrive, -speed);
        setMotor(RFDrive,  speed);
        setMotor(RBDrive,  speed);
        break;

    case TURN_RIGHT:
        setMotor(LFDrive,  speed);
        setMotor(LBDrive,  speed);
        setMotor(RFDrive, -speed);
        setMotor(RBDrive, -speed);
        break;
    }
}

//stops the robot drive (obviously).
void driveStop()
{
    setMotor(LFDrive, 0);
    setMotor(LBDrive, 0);
    setMotor(RFDrive, 0);
    setMotor(RBDrive, 0);
}

//calls driveMove until the robots destination
//is reach (based off of IME readings)
void driveMoveTo(direction direction, int speed,
                 sensor encoder, int target)
{
    //reset encoder to 0
    imeReset(encoder.port);
        
    //start movement
    driveMove(direction, speed);

    //if the target is not a negative value
    if(target >= 0)
    {
        //loop until the target is reached.
        while(getSensor(encoder) < target) delay(1);
    }

    //if the target is a negative value
    else
    {
        //loop until the target is reached
        while(getSensor(encoder) > target) delay(1);
    }

    //stop after the target is reached
    driveStop();
}
