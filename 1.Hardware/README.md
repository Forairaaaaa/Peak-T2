#### 立创开源平台链接：

#### https://oshwhub.com/eedadada/fed36bbc19da4527b237982f9cd09f99

PCB为4层板，电路及布局基本与稚晖君原版Peak无异。

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

#### 焊接建议：

- 鉴于ESP32-PICO-D4封装问题，建议使用钢网配合加热平台或风枪
- 旋转编码器焊盘建议使用烙铁加固，只经过普通加热台焊接容易焊不稳（别问怎么知道的

#### 注意问题：

- **烧录程序时需要接上电池，不然烧录时会出现电压问题报错**
- **烧录程序时需要保持按下编码器，为芯片供电**
- 由于电池座旁边有几个元器件，拔电池插头时要小心方向，别把旁边的小器件也顺下来了（
- PCB底层上的芯片电源使能电阻使用了0603封装，确实不如0402方便（可以直接连锡）
- GPS模块不需要的可以不焊接，或者替换自己的小模块，要注意相关引脚问题，详细在原理图有说明
- 同理MPU6050、触摸屏也可以裁剪掉，这两者使用同一组I2C总线

#### 器件链接参考：

- 电池：[伯朗 导航行车记录仪锂电池大容量通用3.7v聚合物胎压蓝牙耳机5V-tmall.com天猫](https://detail.tmall.com/item.htm?id=579820162048&spm=a1z09.2.0.0.5eaf2e8dkwSGBJ&_u=b2bdtj0f1990) 分类：耐高温80度-603450-1200毫安
- 外壳固定铜柱：[M2*4/5/6/8/9/10/11/12 双通 监控铜柱 滚花安防铜柱（10只）-淘宝网 (taobao.com)](https://item.taobao.com/item.htm?spm=a1z09.2.0.0.5eaf2e8dkwSGBJ&id=555117890802&_u=b2bdtj0fff40) 分类：双通 M2*4
- GPS模块：[ATGM336H GPS 北斗双模模块 飞控 带EEPROM 替代NEO-M8N-淘宝网 (taobao.com)](https://item.taobao.com/item.htm?spm=a1z09.2.0.0.5eaf2e8dkwSGBJ&id=595353912203&_u=b2bdtj0f9a41)
- LCD屏幕：[2寸lcd显示屏2.0寸显示屏高清ips显示屏st7789驱动spi/并口240320-淘宝网 (taobao.com)](https://item.taobao.com/item.htm?spm=a1z09.2.0.0.5eaf2e8dkwSGBJ&id=653306169973&_u=b2bdtj0faa53)
- 电容触摸屏：[2寸CTP电容触摸屏2.0寸小尺寸触摸屏 FT6236U FT6336G CST026-淘宝网 (taobao.com)](https://item.taobao.com/item.htm?spm=a1z09.2.0.0.5eaf2e8dkwSGBJ&id=607113397517&_u=b2bdtj0f8e5c)
- CP2102可用CH9102X代替



![](https://gitee.com/forairaaaaa/peak-t2/raw/master/5.Pics/pcb2.png)



![](https://gitee.com/forairaaaaa/peak-t2/raw/master/5.Pics/pcb.png)



![](https://gitee.com/forairaaaaa/peak-t2/raw/master/5.Pics/sch.png)

