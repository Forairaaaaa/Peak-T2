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




/*=========================
   Hardware Configuration
 *=========================*/

/* Screen */
// #define CONFIG_SCREEN_CS_PIN        PB0
// #define CONFIG_SCREEN_DC_PIN        PA4
// #define CONFIG_SCREEN_RST_PIN       PA6
// #define CONFIG_SCREEN_SCK_PIN       PA5
// #define CONFIG_SCREEN_MOSI_PIN      PA7
#define CONFIG_SCREEN_BLK_PIN       12
#define CONFIG_SCREEN_HOR_RES       240
#define CONFIG_SCREEN_VER_RES       320
#define CONFIG_SCREEN_BUFFER_SIZE   (CONFIG_SCREEN_HOR_RES * CONFIG_SCREEN_VER_RES / 10)

/* Touch screen */
#define CST_DEVICE_ADDR 0x38
#define CST_INT 39

/* Battery */
#define CONFIG_BAT_DET_PIN          37
#define CONFIG_BAT_CHG_DET_PIN      38

/* Buzzer */
#define CONFIG_BUZZ_PIN             25
#define CONFIG_BUZZ_CHANNEL         2
#define CONFIG_SOUND_ENABLE_DEFAULT true

/* GPS */
#define CONFIG_GPS_SERIAL           Serial1
#define CONFIG_GPS_USE_TRANSPARENT  0
#define CONFIG_GPS_BUF_OVERLOAD_CHK 0
#define CONFIG_GPS_TX_PIN           36
#define CONFIG_GPS_RX_PIN           19

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
#define CONFIF_ENCODER_CHANGE_BACKLIGHT_ENABLE true
#define CONFIF_ENCODER_CHANGE_BACKLIGHT_WEIGHT 100

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


#endif
