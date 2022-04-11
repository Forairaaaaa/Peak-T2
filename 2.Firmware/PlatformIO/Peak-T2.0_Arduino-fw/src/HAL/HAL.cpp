#include "HAL.h"

static MillisTaskManager taskManager;


static void HAL_Update_Thread(void* argument)
{
    for (;;)
    {
        HAL::Power_Update();
        HAL::Encoder_Update();
        HAL::Audio_Update();
        delay(30);
    }
}

void HAL::HAL_Init()
{
    /* Print version */
    Serial.begin(115200);
    Serial.println("[Peak-Track]");
    Serial.println("Version: " "1.0");
    Serial.println("Author: " "Forairaaaaa");

    /* Power init */
    Power_Init();

    /* Peripherals init */
    Encoder_Init();
    Buzz_init();
    Audio_Init();
    GPS_Init();
    Clock_Init();
    // SD_Init();
    I2C_Scan();
    IMU_Init();

    /* LCD and Touch screen init */
    Backlight_Init();
    Display_Init();
    Touch_Init();

    /* Update tasks register */
    taskManager.Register(Power_EventMonitor, 100);
    taskManager.Register(GPS_Update, 200);
    taskManager.Register(IMU_Update, 1000);

    /* Crete a higher level thread */
    xTaskCreate(
        HAL_Update_Thread,
        "HALupdate",
        1024,
        NULL,
        2,
        NULL);

    HAL::Audio_PlayMusic("Startup");
}

void HAL::HAL_Update()
{
    // /* Power ctrl update */
    // Power_Update();
    // Power_EventMonitor();
    
    // /* Peripherals update */
    // Encoder_Update();
    // Audio_Update();
    // GPS_Update();
    // IMU_Update();

    taskManager.Running(millis());
}
