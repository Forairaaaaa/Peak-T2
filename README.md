![](https://gitee.com/forairaaaaa/peak-t2/raw/master/5.Pics/Peak-T2.28_s.png)

# 基于ESP32的2.0英寸触摸屏小终端

#### 视频介绍~：

- https://www.bilibili.com/video/BV1934y1e74z?share_source=copy_web

#### 设计参考：

- https://github.com/peng-zhihui/Peak
- https://github.com/FASTSHIFT/X-TRACK

#### 硬件配置：

| 主控     | ESP32-PICO-D4                                             |
| -------- | --------------------------------------------------------- |
| 屏幕     | ST7789 IPS 2.0英寸LCD  SPI接口   分辨率：240x320          |
| 输入设备 | CST026 2.0英寸电容触摸屏  分辨率：240x320  、  旋转编码器 |
| 输出设备 | 一颗用户LED、蜂鸣器                                       |
| 储存     | TF卡槽  SPI接口                                           |
| IMU      | MPU6050  I2C接口                                          |
| GPS      | ATGM336H模块  UART接口                                    |
| 电池     | Li-ion 3.7V 603450 1200mAh                                |
| 电源管理 | ME6215C33M5G + MCP73831                                   |
| USB接口  | Type-C座，CP2102自动下载电路                              |

详细参考链接：[1.Hardware · Forairaaaaa/Peak-T2 - 码云 - 开源中国 (gitee.com)](https://gitee.com/forairaaaaa/peak-t2/tree/master/1.Hardware)





