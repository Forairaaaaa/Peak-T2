#include <Arduino.h>
#include "HAL/HAL.h"
#include "Port/Display.h"
#include "App/App.h"

void setup()
{
    HAL::HAL_Init();
    Port_Init();
    App_Init();
    HAL::Power_SetEventCallback(App_Uninit);
}

void loop()
{
    HAL::HAL_Update();
    delay(20);
}
