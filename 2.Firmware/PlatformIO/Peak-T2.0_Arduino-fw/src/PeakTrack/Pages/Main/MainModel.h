#ifndef MAINMODEL_H
#define MAINMODEL_H

#include "Arduino.h"
#include "HAL/HAL.h"
#include "lvgl.h"
#include "MainView.h"


typedef struct
{
    String Clock;
    String Statellites;
    String Battery;
    String Speed;
    String SpeedAVG;
    String SpeedMAX;
    String Trip;
    String Time;
} DataMainView_t;


typedef struct
{
    float Speed;
    float SpeedAVG;
    float SpeedMAX;
    float Trip;
    double preLong;
    double preLat;
    uint8_t Time_h;
    uint8_t Time_m;
    uint8_t Time_s;
} DataMainModel_t;


class MainModel
{
public:
    void Init();
    void UpdateData();
    void UpdateView();
    void IndevSetup();
private:
    DataMainView_t dataMainView;
    DataMainModel_t dataMainModel;
    void UpdateSport();
};



#endif