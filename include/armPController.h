#ifndef ARMPCONTROLLER_H_
#define ARMPCONTROLLER_H_

#define ARM_FULL_HEIGHT 4095
#define ARM_MIN_HEIGHT 0
#define ARM_LAUNCH_HEIGHT 0

extern double  pidValueArm;
extern int liftControl;

void pidControllerArm();
#endif
