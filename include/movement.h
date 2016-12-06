#ifndef MOVEMENT_H_
#define MOVEMENT_H_
typedef enum direction
{
    FORWARD,
    BACKWARD,
    LEFT_TURN,
    RIGHT_TURN,
    LEFT_TURN_WIDE,
    RIGHT_TURN_WIDE,
    STOP
    }direction;

//function prototypes
void controlDrive(int speed, direction dir);
void controlDriveEnc(int speed, direction dir, int counts);
#endif //MOVEMENT_H_
