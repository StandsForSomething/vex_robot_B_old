# include "main.h"
//////////
//motors//
//////////

//left drive motors
motor LFDrive = {6, true};
motor LBDrive = {7, true};


//right drive motors
motor RFDrive = {4, false};
motor RBDrive = {5, false};

//lift motors
motor liftLeft1Y = {3,false};
motor liftleft2 = {2, false};
motor liftRight1Y = {8, true};
motor liftRight2 = {9, true};
//claw motors
motor claw1 = {1, false};
motor claw2 = {10,true};
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


void encoderSetup()
{
    initEncoderTW(&encoderLeft, 11, 12, true, SPEED, ROTATIONS, 1.0);
    initEncoderTW(&encoderRight, 8, 9, false, SPEED, ROTATIONS, 1.0);
}
