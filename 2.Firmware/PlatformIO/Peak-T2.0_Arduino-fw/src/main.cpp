#include <Arduino.h>
#include "HAL/HAL.h"
#include "Port/Display.h"
#include "PeakTrack/PeakTrack.h"
#include "lv_demo.h"


#include "HAL/HAL_Def.h"


void lvgl_test(char i)
{
    switch (i) {
    case 0:
        lv_demo_benchmark();
        break;
    case 1:
        lv_demo_widgets();
        break;
    case 2:
        lv_demo_stress();
        break;
    case 3:
        lv_demo_keypad_encoder();
        break;
    case 4:
        lv_demo_music();
        break;
    default:
        break;
    } 
}



void setup()
{
    HAL::HAL_Init();
    Port_Init();

    /* lvgl test */
    // lvgl_test(100);
    Peak_Track_init();

    /* Enable lvgl task */
    INIT_DONE();
}

void loop()
{
    HAL::HAL_Update();
}






