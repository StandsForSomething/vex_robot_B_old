#ifndef MOTORS_H_
#define MOTORS_H_

//right motors
extern motor RFDrive;     //port 2, reversed
extern motor RBDrive;     //port 3, reversed

//left motors
extern motor LBDrive;     //port 6, not reversed
extern motor LFDrive;     //port 7, not reversed

extern encoder armEnc;
//arm motors
extern motor armLY;
extern motor armRY;
extern motor armL;
extern motor armR;
extern motorGroup arm;

extern sensor armPot;

#define ARM_POT 14
//digital
//extern sensor powerExpandJumper;    //digital port 1, input, reversed

//analog
//extern sensor tileSelect;        //analog port 1, not reversed
//extern sensor movementSelect;    //analog port 2, not reversed
//extern sensor powerExpand;     //analog port 3, not reversed

//definition for cortex pins
//#define POWER_EXPAND_JUMP 1    //digital port 1

//#define TILE_SELECT 13         //analog port 1
//#define MOVE_SELECT 14         //analog port 2
//#define POWER_EXPAND 15        //analog port 3
#endif
