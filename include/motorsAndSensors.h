#ifndef MOTORS_H_
#define MOTORS_H_
//right motors
motor RFDrive;
motor RBDrive;

//left motors
motor LBDrive;
motor LFDrive;

//digital
sensor powerExpandJumper;
sensor configJumper;

//analog
sensor powerExpand;

//definition for cortex pins
#define POWER_EXPAND_JUMP 1    //digital port 1
#define CONFIG_JUMP 2          //digital port 2

#define POWER_EXPAND 15        //analog port 3
#endif
