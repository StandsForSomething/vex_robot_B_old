#include "main.h"
//////////
//motors//
//////////

//right motors
motor RFDriveI = {2, true};
motor RFDriveO = {3, false};
motor RBDriveI = {4, true};
motor RBDriveO = {5, false};

//left motors
motor LFDriveI = {6, false};
motor LFDriveO = {7, true};
motor LBDriveI = {8, false};
motor LBDriveO = {9, true};

///////////
//sensors//
///////////
//digital
sensor driveControlJumper = {1, DIGITAL, false};
sensor powerExpandJumper = {12, DIGITAL, true};

//analog
sensor powerExpand = {1, ANALOG, false};
//sensor tileSelect = {2, ANALOG, false};
//sensor movementSelect = {3, ANALOG, false};
