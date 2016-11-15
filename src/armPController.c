#include "main.h"

double pid_KpArm = 0.25;
double pidValueArm = 0;
int liftControl = 0;

/*-----------------------------------------------------------------------------*/
/*  pid control task                                                           */
/*-----------------------------------------------------------------------------*/

double  pidSensorCurrentValue = 0;
double  pidError = 0;
int  pidDrive = 0;

void pidControllerArm()
{

    while(true)
    {
        // Read the sensor value and scale
        pidSensorCurrentValue = getSensor(armPot);

        if(abs(liftControl) > 1)
             pidValueArm = pidSensorCurrentValue;

        // calculate error
        pidError =  pidValueArm - pidSensorCurrentValue;

        // calculate drive
        if(abs(liftControl) > 1)
             pidDrive = liftControl;
        else
            pidDrive = pid_KpArm * pidError;

        // limit drive
        if( pidDrive > 127)
            pidDrive = 127;
        if( pidDrive < -127)
            pidDrive = -127;

        setMotor(armLY, pidDrive);
        setMotor(armRY, pidDrive);
        setMotor(armL, pidDrive);
        setMotor(armR, pidDrive);
        // Don't hog cpu
        delay(20);
    }
}
