#include "main.h"
//////////
//motors//
//////////
//
//right motors
motor RFDrive = {5, true};
motor RBDrive = {7, true};

//left motors
motor LBDrive = {8, false};
motor LFDrive = {9, false};

///////////
//sensors//
///////////

//digital
sensor powerExpandJumper = {1, DIGITAL, true};
sensor configJumper = {2,DIGITAL, true};

//analog
sensor powerExpand = {3, ANALOG, false};

//definition for cortex pins
#define POWER_EXPAND_JUMP 1    //digital port 1
#define CONFIG_JUMP 2          //digital port 2

#define POWER_EXPAND 15        //analog port 3
