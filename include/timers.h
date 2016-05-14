//list of timers (must be manually started)
extern unsigned long timer1;
extern unsigned long timer2;
extern unsigned long timer3;
extern unsigned long timer4;

//time since timeLoop started
extern unsigned long  sysTime;

//enable or disable timers
extern bool countTimer1;
extern bool countTimer2;
extern bool countTimer3;
extern bool countTimer4;

//function prototypes
extern unsigned long getSysTime();
extern void timeLoop(void *ignore);
