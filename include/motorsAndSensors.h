#ifndef MOTORS_H_
#define MOTORS_H_

//left drive motors
extern motor LFDrive;  //port 2, reversed
extern motor LBDriveO;  //port 3, not reversed
extern motor LBDriveI;  //port 4, reversed

//right drive motors
extern motor RFDrive;  //port 7, not reversed
extern motor RBDriveO;  //port 8, reversed
extern motor RBDriveI;  //port 9, not reversed

//arm motors
extern motor liftLeft;  //port 4, not reversed
extern motor liftRight1;  //port 5, reversed
extern motor liftRight2;  //port 10, reversed

//claw
extern motor claw; //port 1, not reversed

//digital
extern sensor powerExpandJumper;    //digital port 2, input, reversed

//analog
extern sensor powerExpand;         //analog port 1, not reversed
extern sensor autoSelect;        //analog port 2, not reversed

extern encoder armEnc;
extern encoder encoderLeft;
extern encoder encoderRight;

void encoderSetup();

//definition for cortex pins
#define ENC_RIGHT_TOP 8
#define ENC_RIGHT_BOT 9
#define ENC_LEFT_TOP 11
#define ENC_LEFT_BOT 12
#define ARM_ENC_TOP 6
#define ARM_ENC_BOT 7

#define POWER_EXPAND_JUMP 10       //digital port 2

#define POWER_EXPAND 13            //analog port 1
#define AUTO_SELECT 14           //analog port 2
#endif
