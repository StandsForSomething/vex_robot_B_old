#include "main.h"

void controlDrive(int speed, direction dir)
{
    switch(dir)
    {
    case FORWARD:
        setMotor(LFDrive, speed);
        setMotor(LBDriveI, speed);
        setMotor(LBDriveO, speed);
        setMotor(RFDrive, speed);
        setMotor(RBDriveI, speed);
        setMotor(RBDriveO, speed);
        break;

    case BACKWARD:
        setMotor(LFDrive, -speed);
        setMotor(LBDriveI, -speed);
        setMotor(LBDriveO, -speed);
        setMotor(RFDrive, -speed);
        setMotor(RBDriveI, -speed);
        setMotor(RBDriveO, -speed);
        break;

    case LEFT_TURN:
        setMotor(LFDrive, -speed);
        setMotor(LBDriveI, -speed);
        setMotor(LBDriveO, -speed);
        setMotor(RFDrive, speed);
        setMotor(RBDriveI, speed);
        setMotor(RBDriveO, speed);
        break;

    case RIGHT_TURN:
        setMotor(LFDrive, speed);
        setMotor(LBDriveI, speed);
        setMotor(LBDriveO, speed);
        setMotor(RFDrive, -speed);
        setMotor(RBDriveI, -speed);
        setMotor(RBDriveO, -speed);
        break;

    case LEFT_TURN_WIDE:
        setMotor(LFDrive, 0);
        setMotor(LBDriveI, 0);
        setMotor(LBDriveO, 0);
        setMotor(RFDrive, speed);
        setMotor(RBDriveI, speed);
        setMotor(RBDriveO, speed);
        break;

    case RIGHT_TURN_WIDE:
        setMotor(LFDrive, speed);
        setMotor(LBDriveI, speed);
        setMotor(LBDriveO, speed);
        setMotor(RFDrive, 0);
        setMotor(RBDriveI, 0);
        setMotor(RBDriveO, 0);
        break;

    case LEFT_STRAFE:
        setMotor(LFDrive, -speed);
        setMotor(LBDriveI, speed);
        setMotor(LBDriveO, speed);
        setMotor(RFDrive, speed);
        setMotor(RBDriveI, -speed);
        setMotor(RBDriveO, -speed);
         break;

    case RIGHT_STRAFE:
        setMotor(LFDrive, speed);
        setMotor(LBDriveI, -speed);
        setMotor(LBDriveO, -speed);
        setMotor(RFDrive, -speed);
        setMotor(RBDriveI, speed);
        setMotor(RBDriveO, speed);
         break;

    case STOP:
        setMotor(LFDrive, 0);
        setMotor(LBDriveI, 0);
        setMotor(LBDriveO, 0);
        setMotor(RFDrive, 0);
        setMotor(RBDriveI, 0);
        setMotor(RBDriveO, 0);
        break;

    default:
        return;
        break;
    }
}
void controlDriveEnc(int speed, direction dir, double counts)
{
    encoderReset(encoderRight.shaftEncoder);
    encoderReset(encoderLeft.shaftEncoder);
    controlDrive(speed, dir);
    if(dir == LEFT_TURN_WIDE)
    {
        while(getSensor(encoderRight.parent) < counts)
        {
            printf("%f\n\r", getEncoder(encoderRight));
            delay(20);
        }
    }

    else if(dir == BACKWARD || dir == LEFT_TURN)
    {
        while(getSensor(encoderLeft.parent) > counts)
        {
            printf("%f\n\r", getEncoder(encoderLeft));
            delay(20);
        }
    }

    else
    {
        while(getSensor(encoderLeft.parent) < counts)
        {
            printf("%f\n\r", getEncoder(encoderLeft));
        delay(20);
        }
    }
    controlDrive(0, STOP);
}

void controlLift(int speed)
{
    setMotor(leftLift1, speed);
    setMotor(leftLift2, speed);
    setMotor(rightLift1, speed);
    setMotor(rightLift2, speed);
}

void controlLiftPot(int speed, int potValue)
{
    controlLift(speed);
    if(speed >= 0)
    {
        while(getSensor(armPot) < potValue)
        {
            printf("%f\n\r", getSensor(armPot));
        }
    }

    else
    {
        while(getSensor(armPot) < potValue)
        {
            printf("%f\n\r", getSensor(armPot));
        }
    }
    controlLift(0);
}
