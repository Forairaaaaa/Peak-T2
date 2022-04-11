/*
 * MIT License
 * Copyright (c) 2021 _VIFEXTech
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#ifndef __CONFIG_H
#define __CONFIG_H

/*=========================
   Application configuration
 *=========================*/

#define CONFIG_SYSTEM_SAVE_FILE_PATH          "/SystemSave.json"
#define CONFIG_SYSTEM_SAVE_FILE_BACKUP_PATH   "/.SystemSaveBackup.json"
#define CONFIG_SYSTEM_LANGUAGE_DEFAULT        "en-GB"
#define CONFIG_SYSTEM_TIME_ZONE_DEFAULT       8    // GMT+ 8
#define CONFIG_SYSTEM_SOUND_ENABLE_DEFAULT    true

#define CONFIG_WEIGHT_DEFAULT                 65   // kg

#ifdef ARDUINO
#  define CONFIG_GPS_REFR_PERIOD              1000 // ms
#else
#  define CONFIG_GPS_REFR_PERIOD              10 // ms
#endif

#define CONFIG_GPS_LONGITUDE_DEFAULT          116.391332f
#define CONFIG_GPS_LATITUDE_DEFAULT           39.907415f

#define CONFIG_TRACK_FILTER_OFFSET_THRESHOLD  2 // pixel
#define CONFIG_TRACK_RECORD_FILE_DIR_NAME     "/Track"

#define CONFIG_MAP_USE_WGS84_DEFAULT          false
#define CONFIG_MAP_DIR_PATH_DEFAULT           "/MAP"

#define CONFIG_MAP_EXT_NAME_DEFAULT           "bin"

#ifndef CONFIG_MAP_IMG_PNG_ENABLE
#  define CONFIG_MAP_IMG_PNG_ENABLE           0
#endif

#define CONFIG_ARROW_THEME_DEFAULT            "default"

#define CONFIG_LIVE_MAP_LEVEL_DEFAULT         16

#define CONFIG_LIVE_MAP_DEBUG_ENABLE          0
#if CONFIG_LIVE_MAP_DEBUG_ENABLE
#  define CONFIG_LIVE_MAP_VIEW_WIDTH          240
#  define CONFIG_LIVE_MAP_VIEW_HEIGHT         240
#else
#  define CONFIG_LIVE_MAP_VIEW_WIDTH          LV_HOR_RES
#  define CONFIG_LIVE_MAP_VIEW_HEIGHT         LV_VER_RES
#endif

#define CONFIG_MONKEY_TEST_ENABLE             0
#if CONFIG_MONKEY_TEST_ENABLE
#  define CONFIG_MONKEY_INDEV_TYPE            LV_INDEV_TYPE_ENCODER
#  define CONFIG_MONKEY_PERIOD_MIN            10
#  define CONFIG_MONKEY_PERIOD_MAX            100
#  define CONFIG_MONKEY_INPUT_RANGE_MIN       -5
#  define CONFIG_MONKEY_INPUT_RANGE_MAX       5
#endif


/*=========================
   Hardware Configuration
 *=========================*/

#define NULL_PIN                    PD0

/* Screen */
#define CONFIG_SCREEN_CS_PIN        PB0
#define CONFIG_SCREEN_DC_PIN        PA4
#define CONFIG_SCREEN_RST_PIN       PA6
#define CONFIG_SCREEN_SCK_PIN       PA5
#define CONFIG_SCREEN_MOSI_PIN      PA7
#define CONFIG_SCREEN_BLK_PIN       12

#define CONFIG_SCREEN_HOR_RES       240
#define CONFIG_SCREEN_VER_RES       320
#define CONFIG_SCREEN_BUFFER_SIZE   (CONFIG_SCREEN_HOR_RES * CONFIG_SCREEN_VER_RES / 10)

/* Battery */
#define CONFIG_BAT_DET_PIN          37
#define CONFIG_BAT_CHG_DET_PIN      38

/* Buzzer */
#define CONFIG_BUZZ_PIN             25
#define CONFIG_BUZZ_CHANNEL         2
#define CONFIG_SOUND_ENABLE_DEFAULT true

/* GPS */
#define CONFIG_GPS_SERIAL           Serial2
#define CONFIG_GPS_USE_TRANSPARENT  0
#define CONFIG_GPS_BUF_OVERLOAD_CHK 0
#define CONFIG_GPS_TX_PIN           PA3
#define CONFIG_GPS_RX_PIN           PA2

/* IMU */
#define CONFIG_IMU_INT1_PIN         32
#define CONFIG_IMU_INT2_PIN         33

/* I2C */
#define CONFIG_MCU_SDA_PIN          32
#define CONFIG_MCU_SCL_PIN          33

/* Encoder */
#define CONFIG_ENCODER_B_PIN        34
#define CONFIG_ENCODER_A_PIN        35
#define CONFIG_ENCODER_PUSH_PIN     27

/* Power */
#define CONFIG_POWER_EN_PIN         21
#define CONFIG_POWER_WAIT_TIME      1000
#define CONFIG_POWER_SHUTDOWM_DELAY 5000

/* Debug USART */
#define CONFIG_DEBUG_SERIAL         Serial

/* SD CARD */
#define CONFIG_SD_SPI               SPI_SD
#define CONFIG_SD_CD_PIN            -1
#define CONFIG_SD_MOSI_PIN          PB15
#define CONFIG_SD_MISO_PIN          PB14
#define CONFIG_SD_SCK_PIN           PB13
#define CONFIG_SD_CS_PIN            15
#define CONFIG_SD_DET_PIN           22

/* Stack Info */
#define CONFIG_USE_STACK_INFO       0
#define CONFIG_SHOW_HEAP_INFO       0



#endif
