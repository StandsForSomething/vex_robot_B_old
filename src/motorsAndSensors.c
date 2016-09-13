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
motor armLY = {7,  true};
motor armRY = {6,  false};
motor armLO = {8,  false};
motor armRO = {9,  true};
motor armLI = {1,  false};
motor armRI = {10, true};

///////////
//sensors//
///////////
//digital
//sensor powerExpandJumper = {1, DIGITAL, true};                       

//analog
//sensor tileSelect = {1, ANALOG, false};
//sensor movementSelect = {2, ANALOG, false};
//sensor powerExpand = {3, ANALOG, false};
