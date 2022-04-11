#include "HAL.h"

M5Touch Touch;

void HAL::Touch_Init()
{
    /* Touch init */
    Touch.begin();
}

// /* Don't work well */
bool HAL::Touch_Ispressed()
{
    bool istouched = Touch.ispressed();
    // bool istouched = false;

    // if (digitalRead(CST_INT) == LOW) {
    //     istouched = true;
    // } else {
    //     istouched = false;
    // }

    return istouched;
}

void HAL::Touch_GetPressPoint(TouchPoint_t* coordinate)
{
    *coordinate = Touch.getPressPoint();
}
