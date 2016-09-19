#include "main.h"

double pid_KpArm = 0.2;
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
        pidSensorCurrentValue = getEncoder(armEnc);

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

        //commented out for now until I figure out the correct values
        /*if((pidRequestedValueArm > 3384 || pidRequestedValueArm > 3384 || SensorValue[ArmLimit1]) && pidDrive > 0)
        {
           pidDrive = 0;
           pidRequestedValueArm = 3384;
        }

        if((pidRequestedValueArm < 2055 || pidRequestedValueArm < 2055 || SensorValue[ArmLimit2]) && pidDrive < 0)
        pidDrive = 0;*/
        
        setMotor(armLY, pidDrive);
        setMotor(armRY, pidDrive);
        setMotor(armLO, pidDrive);
        setMotor(armRO, pidDrive);
        setMotor(armLI, pidDrive);
        setMotor(armRI, pidDrive);
        // Don't hog cpu
        delay(20);
    }
}
