#ifndef LCDITEM_H_
#define LCDITEM_H_

typedef struct LCDItem
{
    char *LCDText;
    void (*function)();
}LCDItem;

extern LCDItem *LCDMenuItems;
extern int currentSelection;

#endif
