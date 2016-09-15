#ifndef HARDWARESETUP_H_
#define HARDWARESETUP_H_

typedef enum sensorType {ANALOG, DIGITAL, DIGITAL_OUT, OTHER}sensorType;
typedef enum encoderType {IME, TWO_WIRE, ONE_WIRE}encoderType;
typedef enum encoderGetType {COUNTS, VELOCITY, ROTATIONS, RPM}encoderGetType;
typedef enum motorGearing {TORQUE, SPEED, TURBO}motorGearing;

typedef struct sensor
{
    int port;
    sensorType sensorType;
    bool reversed;

    //if sensorType is OTHER getSensor() will run whatever this points to.
    double (*sensorValue)();

    //this is designed to allow inheritance and allow miniplation of the dirived
    //structure with the parent structure has been passed as an argument.
    struct child *child;
}sensor;

//this should be initialized with initEncoder().
typedef struct encoder
{
    sensor parent;
    encoderType encoderType;

    //COUNTS will just give the current number of ticks on an encoder
    //VELOCITY will give the value returned from imeGetVelocity()
    //ROTATIONS should be obvious
    //RPM should also be obvious
    //can be changed as need or you can use multiple encoder structures for one
    //physical encoder, your choice
    encoderGetType encoderGetType;

    //the divisors for calculating the number of rotations and RPM of a motor,
    //will vary depending on motor gearing, if your using a shaft encoder this
    //can be ignored.
    float countsDivisor;
    float velocityDivisor;

    //for any external gearing
    float gearRatio;

    //used if a shaft encoder is being used.
    Encoder shaftEncoder;
    int port2;
}encoder;

typedef struct motor
{
    int port;
    bool reversed;

    //does not need to be set.
    encoder *encoder;
}motor;

typedef struct motorGroup
{
    motor *group[10];
}motorGroup;

//function prototypes
void setMotor(struct motor motor, int speed);
double getSensor(struct sensor sensor);
void setOutput(struct sensor sensor, bool value);
void initEncoder(encoder *initEncoder, int port1, int port2, bool reversed,
                 motorGearing motorGearing, encoderType encoderType,
                 encoderGetType encoderGetType, float gearRatio);
double getEncoder(encoder encoderParent);
double getEncoderMode(encoder encoderParent, encoderGetType encoderGetType);
void initEncoderIme(encoder *encoder, int port, bool reversed,
                    motorGearing motorGearing, encoderGetType encoderGetType,
                    float gearRatio);
void initEncoderTW(encoder *encoder, int port1, int port2, bool reversed,
                    motorGearing motorGearing, encoderGetType encoderGetType,
                   float gearRatio);
void initEncoderOW(encoder *encoder, int port, bool reversed,
                    motorGearing motorGearing, encoderGetType encoderGetType,
                   float gearRatio);
#endif //HARDWARESETUP_H_
