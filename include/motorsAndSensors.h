#ifndef MOTORS_H_
#define MOTORS_H_

//right motors
extern motor RFDriveI;     //port 2, reversed
extern motor RFDriveO;     //port 3, reversed
extern motor RBDriveI;     //port 2, reversed
extern motor RBDriveO;     //port 3, reversed

//left motors
extern motor LFDriveI;     //port 6, not reversed
extern motor LFDriveO;     //port 7, not reversed
extern motor LBDriveI;     //port 2, reversed
extern motor LBDriveO;     //port 3, reversed

//digital
extern sensor driveControlJumper;
extern sensor powerExpandJumper;    //digital port 2, input, reversed

//analog
extern sensor powerExpand;         //analog port 1, not reversed
extern sensor autoSelect;        //analog port 2, not reversed

extern encoder encoderLeft;
extern encoder encoderRight;

void encoderSetup();

//definition for cortex pins
#define DRIVE_CONTROL_JUMP 1
#define POWER_EXPAND_JUMP 12       //digital port 2

#define POWER_EXPAND 13            //analog port 1
#define AUTO_SELECT 14           //analog port 2
#endif
