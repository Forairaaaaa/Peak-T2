#include "HAL.h"

static bool IsEnable = true;

static int32_t duration = 0;
static uint32_t freq = 0;


/* Buzzer thread */
static void BuzzerThread(void* argument)
{
    for (;;)
    {
        if (duration > 0)
        {
            ledcWriteTone(CONFIG_BUZZ_CHANNEL, freq);
            delay(duration);
            ledcWriteTone(CONFIG_BUZZ_CHANNEL, 0);

            duration = 0;
        }

        delay(50);
    }
}

void HAL::Buzz_init()
{
    // pinMode(CONFIG_BUZZ_PIN, OUTPUT);


    pinMode(CONFIG_BUZZ_PIN, OUTPUT);
    ledcAttachPin(CONFIG_BUZZ_PIN, CONFIG_BUZZ_CHANNEL);
    ledcSetup(CONFIG_BUZZ_CHANNEL, 0, 8);
    ledcWriteTone(CONFIG_BUZZ_CHANNEL, 0);

    // Create Buzzer thread
    xTaskCreate(
        BuzzerThread,
        "BuzzerThread",
        800,
        NULL,
        1,
        NULL);
}

void HAL::Buzz_SetEnable(bool en)
{
    // if(!en)
    // {
    //     Buzz_Tone(0);
    // }

    IsEnable = en;
}

void HAL::Buzz_Tone(uint32_t _freq, int32_t _duration)
{
    // if(!IsEnable)
    // {
    //     return;
    // }

    // if(duration >= 0)
    // {
    //     // tone(CONFIG_BUZZ_PIN, freq, duration);

    //     ledcWriteTone(CONFIG_BUZZ_CHANNEL, _freq);
    // }
    // else
    // {
    //     // tone(CONFIG_BUZZ_PIN, freq);

    //     freq = _freq;
    //     duration = _duration;
    // }
    
    if (!IsEnable)
        return;

    if (_duration == 0)
    {
        ledcWriteTone(CONFIG_BUZZ_CHANNEL, _freq);
    } else
    {
        freq = _freq;
        duration = _duration;
    }
}
