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
