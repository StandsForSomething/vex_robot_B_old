#ifndef HARDWARESETUP_H_
#define HARDWARESETUP_H_

//motor structure
typedef struct motor
{
	int port;
	bool reversed;
}motor;

//right motors
extern motor RFDrive;     //port 2, reversed
extern motor RBDrive;     //port 3, reversed

//left motors
extern motor LBDrive;     //port 6, not reversed
extern motor LFDrive;     //port 7, not reversed

//arm motors
extern motor armLY;
extern motor armRY;
extern motor armLO;
extern motor armRO;
extern motor armLI;
extern motor armRI;

///////////
//sensors//
///////////

//well, technically DIGITAL_OUT isn't a sensor but whatever.
typedef enum sensorType {ANALOG, DIGITAL, DIGITAL_OUT}sensorType;

//sensor structure
typedef struct sensor
{
    int port;
    sensorType sensortype;
    bool reversed;
}sensor;

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


//function prototypes
extern void setMotor(struct motor theMotor, int speed);
extern int getSensor(struct sensor theSensor);
extern void setOutput(struct sensor theSensor, bool value);

#endif //HARDWARESETUP_H_
