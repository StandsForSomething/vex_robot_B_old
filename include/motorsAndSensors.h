#ifndef MOTORS_H_
#define MOTORS_H_

//right motors
extern motor RFDrive;     //port 2, reversed
extern motor RBDriveI;     //port 2, reversed
extern motor RBDriveO;     //port 3, reversed

//left motors
extern motor LFDrive;     //port 6, not reversed
extern motor LBDriveI;     //port 2, reversed
extern motor LBDriveO;     //port 3, reversed

extern motor leftLift1;
extern motor leftLift2;
extern motor rightLift1;
extern motor rightLift2;

//digital
extern sensor powerExpandJumper;    //digital port 2, input, reversed

//analog
extern sensor powerExpand;         //analog port 1, not reversed
extern sensor autoSelect;        //analog port 2, not reversed
extern sensor armPot;

extern encoder encoderLeft;
extern encoder encoderRight;

void encoderSetup();

//definition for cortex pins
#define ENC_RIGHT_TOP 8
#define ENC_RIGHT_BOT 9
#define ENC_LEFT_TOP 11
#define ENC_LEFT_BOT 12

#define POWER_EXPAND_JUMP 10       //digital port 2

#define POWER_EXPAND 13            //analog port 1
#define AUTO_SELECT 14           //analog port 2
#define ARM_POT 15
#endif
