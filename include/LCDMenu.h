#ifndef LCDITEM_H_
#define LCDITEM_H_

typedef struct LCDItem
{
    char *LCDText;
    void (*function)();
}LCDItem;

extern LCDItem *LCDMenuItems;
extern int currentSelection;
extern sensor selectionPot;

void LCDMenuTask(void *ignore);
void newItem(char* itemText, void (*itemFunction)());
#endif
