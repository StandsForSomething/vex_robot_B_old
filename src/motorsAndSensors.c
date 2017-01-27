#include "main.h"
//////////
//motors//
//////////

//left drive motors
motor LFDrive = {2, true};
motor LBDriveO = {3, false};
motor LBDriveI = {4, true};

//right drive motors
motor RFDrive = {7, false};
motor RBDriveO = {8, true};
motor RBDriveI = {9, false};

//lift motors
motor liftLeft = {5, false};
motor liftRight1 = {6, true};
motor liftRight2 = {10, true};

//claw motors
motor claw = {1, false};

///////////
//sensors//
///////////
//digital
sensor powerExpandJumper = {10, DIGITAL, true};
//analog
sensor powerExpand = {1, ANALOG, false};
sensor autoSelect = {2, ANALOG, false};
sensor armPot = {3, ANALOG, false};

//encoders
encoder encoderLeft;
encoder encoderRight;
encoder armEnc;

void encoderSetup()
{
    initEncoderTW(&armEnc, 6, 7, false, TORQUE, COUNTS, 1.0);
    initEncoderTW(&encoderLeft, 11, 12, true, SPEED, ROTATIONS, 1.0);
    initEncoderTW(&encoderRight, 8, 9, false, SPEED, ROTATIONS, 1.0);
}
