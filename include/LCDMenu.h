#ifndef LCDITEM_H_
#define LCDITEM_H_

#define NUM_OF_ITEMS 1

typedef struct LCDItem
{
    char *LCDText;
    void (*function)();
}LCDItem;

extern LCDItem LCDMenuItem[NUM_OF_ITEMS];
extern int currentSelection;

#endif
