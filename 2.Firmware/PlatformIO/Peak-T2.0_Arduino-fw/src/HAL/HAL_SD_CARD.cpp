#include "HAL.h"
#include "HAL/Config/Config.h"
// #include "SdFat.h"

#include "SPI.h"
#include "SD.h"

// static SdFat SD(&CONFIG_SD_SPI);

static bool SD_IsReady = false;
static uint64_t SD_CardSize = 0;
const char* SD_type = "UNKNOWN";

static HAL::SD_CallbackFunction_t SD_EventCallback = nullptr;

/*
 * User provided date time callback function.
 * See SdFile::dateTimeCallback() for usage.
 */
// static void SD_GetDateTime(uint16_t* date, uint16_t* time)
// {
//     // User gets date and time from GPS or real-time
//     // clock in real callback function
//     HAL::Clock_Info_t clock;
//     HAL::Clock_GetInfo(&clock);

//     // return date using FAT_DATE macro to format fields
//     *date = FAT_DATE(clock.year, clock.month, clock.day);

//     // return time using FAT_TIME macro to format fields
//     *time = FAT_TIME(clock.hour, clock.minute, clock.second);
// }

static bool SD_CheckDir(const char* path)
{
    bool retval = true;
    if(!SD.exists(path))
    {
        Serial.printf("SD: Auto create path \"%s\"...", path);
        retval = SD.mkdir(path);
        Serial.println(retval ? "success" : "failed");
    }
    return retval;

    // File myFile = SD.open("/test.txt", FILE_WRITE);
    // if (myFile)
    // {
    //     myFile.println("testing 1, 2, 3.");
    //     // 关闭文件打开状态
    //     myFile.close();
    // }

    // // Serial.printf("Creat Dir: %s", path);
    // if(SD.mkdir(path)){
    //     Serial.printf("Creat Dir: %s...", path);;
    //     return true;
    // } else {
    //     // Serial.print("mkdir failed");
    //     return false;
    // }
}

bool HAL::SD_Init()
{
    bool retval = true;

    // pinMode(CONFIG_SD_CD_PIN, INPUT_PULLUP);
    // if(digitalRead(CONFIG_SD_CD_PIN))
    // {
    //     Serial.println("SD: CARD was not inserted");
    //     retval = false;
    // }

    Serial.print("SD: init...");
    // retval = SD.begin(CONFIG_SD_CS_PIN, SD_SCK_MHZ(30));


    pinMode(CONFIG_SD_DET_PIN, INPUT);
    
    // SPIClass* sd_spi = new SPIClass(HSPI);     // another SPI
    // retval = SD.begin(15, *sd_spi, 80000000);  // SD-Card SS pin is 15
    // retval = SD.begin(15, *sd_spi);  // SD-Card SS pin is 15
    retval = SD.begin(15);  // SD-Card SS pin is 15

    SD_GetTypeName();
    if (SD.cardType() == CARD_NONE)
    {
        Serial.println("No SD card attached");
        return false;
    }
    
    if(retval)
    {
        SD_CardSize = SD.cardSize() / (1024 * 1024);
        // SdFile::dateTimeCallback(SD_GetDateTime);
        SD_CheckDir("/MAP");
        Serial.printf(
            "success, Type: %s , Size: %0.2f MB\r\n",
            SD_type,
            SD_GetCardSizeMB()
        );
    }
    else
    {
        Serial.println("failed");
    }


    // if(retval)
    // {
    //     SD_CardSize = SD.card()->cardSize();
    //     SdFile::dateTimeCallback(SD_GetDateTime);
    //     SD_CheckDir(CONFIG_TRACK_RECORD_FILE_DIR_NAME);
    //     Serial.printf(
    //         "success, Type: %s, Size: %0.2f GB\r\n",
    //         SD_GetTypeName(),
    //         SD_GetCardSizeMB() / 1024.0f
    //     );
    // }
    // else
    // {
    //     Serial.printf("failed: 0x%x\r\n", SD.cardErrorCode());
    // }

    SD_IsReady = retval;

    return retval;
}

bool HAL::SD_GetReady()
{
    return SD_IsReady;
}

float HAL::SD_GetCardSizeMB()
{
// #   define CONV_MB(size) (size*0.000512f)
//     return CONV_MB(SD_CardSize);
    return SD_CardSize;
}

const char* HAL::SD_GetTypeName()
{
    uint8_t cardType = SD.cardType();

    if (cardType == CARD_MMC)
    {
        // Serial.println("MMC");
        SD_type = "MMC";
    } else if (cardType == CARD_SD)
    {
        // Serial.println("SDSC");
        SD_type = "SDSC";
    } else if (cardType == CARD_SDHC)
    {
        // Serial.println("SDHC");
        SD_type = "SDHC";
    } else
    {
        // Serial.println("UNKNOWN");
        SD_type = "UNKNOWN";
    }

    return SD_type;
}

static void SD_Check(bool isInsert)
{
    if(isInsert)
    {
        bool ret = HAL::SD_Init();

        if(ret && SD_EventCallback)
        {
            SD_EventCallback(true);
        }

        HAL::Audio_PlayMusic(ret ? "DeviceInsert" : "Error");
    }
    else
    {
        SD_IsReady = false;

        if(SD_EventCallback)
        {
            SD_EventCallback(false);
            SD_CardSize = 0;
        }

        HAL::Audio_PlayMusic("DevicePullout");
    }
}

void HAL::SD_SetEventCallback(SD_CallbackFunction_t callback)
{
    SD_EventCallback = callback;
}

void HAL::SD_Update()
{
    // bool isInsert = (digitalRead(CONFIG_SD_CD_PIN) == LOW);
    bool isInsert = (digitalRead(CONFIG_SD_DET_PIN) == LOW);

    CM_VALUE_MONITOR(isInsert, SD_Check(isInsert));
}
