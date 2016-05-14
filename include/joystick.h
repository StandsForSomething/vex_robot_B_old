#ifndef JOYSTICK_H_
#define JOYSTICK_H_

////////////////
//controller 1//
////////////////

//joystick definitions
#define C1RX joystickGetAnalog(1, 1)
#define C1RY joystickGetAnalog(1, 2)
#define C1LY joystickGetAnalog(1, 3)
#define C1LX joystickGetAnalog(1, 4)

//acceleration definitions (that will probally never get used)
#define C1AX joystickGetAnalog(1, ACCEL_X)
#define C1AY joystickGetAnalog(1, ACCEL_Y)

//button definitions
#define C1_5U joystickGetDigital(1, 5, JOY_UP)
#define C1_5D joystickGetDigital(1, 5, JOY_DOWN)

#define C1_6U joystickGetDigital(1, 6, JOY_UP)
#define C1_6D joystickGetDigital(1, 6, JOY_DOWN)

#define C1_7U joystickGetDigital(1, 7, JOY_UP)
#define C1_7D joystickGetDigital(1, 7, JOY_DOWN)
#define C1_7L joystickGetDigital(1, 7, JOY_LEFT)
#define C1_7R joystickGetDigital(1, 7, JOY_RIGHT)
    
#define C1_8U joystickGetDigital(1, 8, JOY_UP)
#define C1_8D joystickGetDigital(1, 8, JOY_DOWN)
#define C1_8L joystickGetDigital(1, 8, JOY_LEFT)
#define C1_8R joystickGetDigital(1, 8, JOY_RIGHT)


////////////////
//controller 2//
////////////////

//joystick definitions
#define C2RX joystickGetAnalog(2, 1)
#define C2RY joystickGetAnalog(2, 2)
#define C2LY joystickGetAnalog(2, 3)
#define C2LX joystickGetAnalog(2, 4)

//acceleration definitions (that will probally never get used)
#define C2AX joystickGetAnalog(2, ACCEL_X)
#define C2AY joystickGetAnalog(2, ACCEL_Y)

//button definitions
#define C2_5U joystickGetDigital(2, 5, JOY_UP)
#define C2_5D joystickGetDigital(2, 5, JOY_DOWN)

#define C2_6U joystickGetDigital(2, 6, JOY_UP)
#define C2_6D joystickGetDigital(2, 6, JOY_DOWN)

#define C2_7U joystickGetDigital(2, 7, JOY_UP)
#define C2_7D joystickGetDigital(2, 7, JOY_DOWN)
#define C2_7L joystickGetDigital(2, 7, JOY_LEFT)
#define C2_7R joystickGetDigital(2, 7, JOY_RIGHT)

#define C2_8U joystickGetDigital(2, 8, JOY_UP)
#define C2_8D joystickGetDigital(2, 8, JOY_DOWN)
#define C2_8L joystickGetDigital(2, 8, JOY_LEFT)
#define C2_8R joystickGetDigital(2, 8, JOY_RIGHT)

#endif //JOYSTICK_H_
