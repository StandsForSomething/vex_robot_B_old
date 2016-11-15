#include "main.h"
//////////
//motors//
//////////

//right motors
motor RFDrive = {2, true};
motor RBDrive = {3, true};

//left motors
motor LBDrive = {4, false};
motor LFDrive = {5, false};

//arm encoder
encoder armEnc;

//arm motors
motor armRY = {6, true};
motor armLY = {7, false};
motor armL  = {8, false};
motor armR  = {9, true};

motorGroup arm;

sensor armPot = {1, ANALOG, false};

///////////
//sensors//
///////////
//digital
//sensor powerExpandJumper = {1, DIGITAL, true};

//analog
//sensor tileSelect = {1, ANALOG, false};
//sensor movementSelect = {2, ANALOG, false};
//sensor powerExpand = {3, ANALOG, false};
