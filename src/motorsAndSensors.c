#include "main.h"
//////////
//motors//
//////////

//right motors
motor RFDriveI = {2, false};
motor RFDriveO = {3, false};
motor RBDriveI = {4, false};
motor RBDriveO = {5, false};

//left motors
motor LFDriveI = {6, true};
motor LFDriveO = {7, true};
motor LBDriveI = {8, true};
motor LBDriveO = {9, true};

///////////
//sensors//
///////////
//digital
sensor driveControlJumper = {1, DIGITAL, false};
sensor powerExpandJumper = {12, DIGITAL, true};

//analog
sensor powerExpand = {1, ANALOG, false};
sensor autoSelect = {2, ANALOG, false};

//encoders
encoder encoderLeft;
encoder encoderRight;

void encoderSetup()
{
    initEncoderTW(&encoderLeft, 11, 12, false, SPEED, ROTATIONS, 1.0);
    initEncoderTW(&encoderRight, 8, 9, false, SPEED, ROTATIONS, 1.0);
}
