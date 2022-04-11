#include "HAL.h"
#include "ButtonEvent.h"

static ButtonEvent EncoderPush(CONFIG_POWER_SHUTDOWM_DELAY);

static bool EncoderEnable = true;
static volatile int16_t EncoderDiff = 0;
static bool EncoderDiffDisable = false;

static uint32_t backLight = 0;

// static void Buzz_Handler(int dir)
// {
//     static const uint16_t freqStart = 2000;
//     static uint16_t freq = freqStart;
//     static uint32_t lastRotateTime;

//     if(millis() - lastRotateTime > 1000)
//     {
//         freq = freqStart;
//     }
//     else
//     {
//         if(dir > 0)
//         {
//             freq += 100;
//         }

//         if(dir < 0)
//         {
//             freq -= 100;
//         }

//         freq = constrain(freq, 100, 20 * 1000);
//     }

//     lastRotateTime = millis();
//     HAL::Buzz_Tone(freq, 5);
// }

static void Encoder_EventHandler()
{
    // if(!EncoderEnable || EncoderDiffDisable)
    // {
    //     return;
    // }

    // int dir = (digitalRead(CONFIG_ENCODER_B_PIN) == LOW ? -1 : +1);
    // EncoderDiff += dir;
    // Buzz_Handler(dir);


    if (!EncoderEnable || EncoderDiffDisable)
    {
        return;
    }

    static volatile int count, countLast;
    static volatile uint8_t a0, b0;
    static volatile uint8_t ab0;
    uint8_t a = digitalRead(CONFIG_ENCODER_A_PIN);
    uint8_t b = digitalRead(CONFIG_ENCODER_B_PIN);
    if (a != a0)
    {
        a0 = a;
        if (b != b0)
        {
            b0 = b;
            count += ((a == b) ? 1 : -1);
            if ((a == b) != ab0)
            {
                count += ((a == b) ? 1 : -1);
            }
            ab0 = (a == b);
        }
    }

    if (count != countLast)
    {
        EncoderDiff += (count - countLast) > 0 ? 1 : -1;
        countLast = count;
    }

}

static void Encoder_PushHandler(ButtonEvent* btn, int event)
{
    if(event == ButtonEvent::EVENT_PRESSED)
    {
        HAL::Buzz_Tone(500, 20);
        EncoderDiffDisable = true;
    }
    else if(event == ButtonEvent::EVENT_RELEASED)
    {
        HAL::Buzz_Tone(700, 20);
        EncoderDiffDisable = false;
    }
    else if(event == ButtonEvent::EVENT_LONG_PRESSED)
    {
        HAL::Audio_PlayMusic("Shutdown");
        HAL::Power_Shutdown();
    }
}

void HAL::Encoder_Init()
{
    // pinMode(CONFIG_ENCODER_A_PIN, INPUT_PULLUP);
    // pinMode(CONFIG_ENCODER_B_PIN, INPUT_PULLUP);
    // pinMode(CONFIG_ENCODER_PUSH_PIN, INPUT_PULLUP);

    // attachInterrupt(CONFIG_ENCODER_A_PIN, Encoder_EventHandler, FALLING);

    // EncoderPush.EventAttach(Encoder_PushHandler);

    pinMode(CONFIG_ENCODER_A_PIN, INPUT_PULLUP);
    pinMode(CONFIG_ENCODER_B_PIN, INPUT_PULLUP);
    pinMode(CONFIG_ENCODER_PUSH_PIN, INPUT_PULLUP);
    attachInterrupt(CONFIG_ENCODER_A_PIN, Encoder_EventHandler, CHANGE);
    EncoderPush.EventAttach(Encoder_PushHandler);

}

void HAL::Encoder_Update()
{
    EncoderPush.EventMonitor(Encoder_GetIsPush());
}

void changeBacklight(int16_t diff)
{
    backLight = HAL::Backlight_GetValue() - (diff * CONFIF_ENCODER_CHANGE_BACKLIGHT_WEIGHT);

    if (backLight > 1024)
        HAL::Buzz_Tone(900, 40);
    
    // HAL::Backlight_SetValue(backLight);
    HAL::Backlight_SetGradual(backLight, 100);
}

int32_t HAL::Encoder_GetDiff()
{
    // int32_t diff = EncoderDiff;
    // EncoderDiff = 0;
    // return diff;

    int16_t diff = -EncoderDiff / 2;
    if (diff != 0)
    {
        // EncoderDiff是实际的脉冲数；把本次变量用掉了，需要重新置0
        EncoderDiff = 0;
        // Encoder_RotateHandler(diff);
        HAL::Buzz_Tone(300, 5);

        #if CONFIF_ENCODER_CHANGE_BACKLIGHT_ENABLE == true
            changeBacklight(diff);
        #endif
    }

    return diff;
}

bool HAL::Encoder_GetIsPush()
{
    if(!EncoderEnable)
    {
        return false;
    }
    
    return (digitalRead(CONFIG_ENCODER_PUSH_PIN) == LOW);
}

void HAL::Encoder_SetEnable(bool en)
{
    EncoderEnable = en;
}
