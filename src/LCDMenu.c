#include "main.h"

LCDItem LCDMenuItem[NUM_OF_ITEMS];
int currentSelection;

//divides all possible potentiometer values between all the items so that all
//items have an equal size range of values where they're selected.
int potSelectionSize = 4095 / NUM_OF_ITEMS;

void LCDMenu(sensor selectionPot)
{
    int selectionRangeUpper = potSelectionSize;
    int selectionRangeLower = 0;

    //loop through all the items to decide what should be displayed
    for(int i = 0; i < NUM_OF_ITEMS; i++)
    {
        //if the potentiometer is within the selection range of item i
        if(getSensor(selectionPot) >= selectionRangeLower &&
           getSensor(selectionPot) <= selectionRangeUpper)
        {
            //change the current selection to i
            currentSelection = i;

            //display the selection on line 1 of the LCD pluged int uart1
            lcdSetText(uart1, 1, LCDMenuItem[i].LCDText);

            //if there is more than one item and the last item isn't the current
            //selection
            if(NUM_OF_ITEMS > 1 && i != NUM_OF_ITEMS-1)
            {
                //display the next selection
                lcdSetText(uart1, 2, LCDMenuItem[i+1].LCDText);
            }
        }

        //set the selection range for i+1
        selectionRangeLower = selectionRangeUpper;
        selectionRangeUpper += potSelectionSize;
    }
}
