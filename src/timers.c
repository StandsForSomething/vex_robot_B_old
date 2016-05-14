#include "main.h"

//list of timers (must be manually started)
unsigned long timer1;
unsigned long timer2;
unsigned long timer3;
unsigned long timer4;

//time since timeLoop started
unsigned long  sysTime;

bool countTimer1;
bool countTimer2;
bool countTimer3;
bool countTimer4;

//sysTime isn't made a global so it can't
//be set externally, so it needs an accessor
unsigned long getSysTime()
{
    return sysTime;
}

//this will be made a task in initialize().
void timeLoop(void *ignore)
{
    //infinite loop
    while(1)
    {
        //increment each timer if it is enabled (sysTime is always enable)
        //I really don't care about overflow, it would take over a month and
        //a half for an unsigned long to overflow.
        if(countTimer1)
            timer1++;

        if(countTimer2)
            timer2++;

        if(countTimer3)
            timer3++;
        
        if(countTimer4)
            timer4++;

        sysTime++;

        //each count on a timer is 1 millisecond.
        delay(1);
    }
}
