#include "MainModel.h"

HAL::GPS_Info_t gps_info;
HAL::Clock_Info_t clock_info;
HAL::Power_Info_t battery_info;

static uint8_t SportTick = 0;

void MainModel::Init()
{
    /* View data init */
    // dataMainView.Battery = "00";
    // dataMainView.Clock = "NO SIGNAL";
    // dataMainView.Statellites = "0";
    // dataMainView.Speed = "00.0";
    // dataMainView.SpeedAVG = "00 km/h";
    // dataMainView.SpeedMAX = "00 km/h";
    // dataMainView.Trip = "00 km";
    // dataMainView.Time = "00:00:00";
    /* Model data init */
    memset(&dataMainModel, 0, sizeof(DataMainModel_t));
}


void MainModel::UpdateData()
{
    /* GPS relevant */
    if (HAL::GPS_LocationIsValid())
    {
        /* Get info from GPS */
        HAL::GPS_GetInfo(&gps_info);
        /* Update speed */
        dataMainModel.Speed = gps_info.speed;
        dataMainView.Speed = gps_info.speed;
        /* Update number of statellites */
        dataMainView.Statellites = gps_info.satellites;
        /* Update clock */
        uint8_t hourTemp = gps_info.clock.hour + 8;
        if (hourTemp >= 24)
            hourTemp -= 24;
        dataMainView.Clock = hourTemp;
        dataMainView.Clock += " : ";
        if (gps_info.clock.minute < 10)
            dataMainView.Clock += "0";
        dataMainView.Clock += gps_info.clock.minute;

    } else {
        /* No signal */
        dataMainView.Speed = "00.0";
        dataMainView.Statellites = "0";
        dataMainView.Clock = "NO SIGNAL";
    }

    /* Update sport */
    UpdateSport();
    
    /* Update battery info */
    HAL::Power_GetInfo(&battery_info);
    dataMainView.Battery = battery_info.usage;

    /* Update speed AVG info */
    dataMainView.SpeedAVG = dataMainModel.SpeedAVG;
    dataMainView.SpeedAVG += " km/h";

    /* Update speed Max info */
    dataMainView.SpeedMAX = dataMainModel.SpeedMAX;
    dataMainView.SpeedMAX += " km/h";

    /* Update trip info */
    dataMainView.Trip = dataMainModel.Trip;
    dataMainView.Trip += " km";

    /* Update time info */
    if (dataMainModel.Time_h < 10) {
        dataMainView.Time = "0";
        dataMainView.Time += dataMainModel.Time_h;
    } else {
        dataMainView.Time = dataMainModel.Time_h;
    }
    dataMainView.Time += ":";
    if (dataMainModel.Time_m < 10)
        dataMainView.Time += "0";
    dataMainView.Time += dataMainModel.Time_m;
    dataMainView.Time += ":";
     if (dataMainModel.Time_s < 10)
        dataMainView.Time += "0";
    dataMainView.Time += dataMainModel.Time_s;
}


void MainModel::UpdateView()
{
    lv_label_set_text(ui_LabelClock, dataMainView.Clock.c_str());
    lv_label_set_text(ui_LabelSatellite, dataMainView.Statellites.c_str());
    lv_label_set_text(ui_LabelBattery, dataMainView.Battery.c_str());
    lv_label_set_text(ui_LabelSpeed, dataMainView.Speed.c_str());
    lv_label_set_text(ui_LabelSpeedAVG, dataMainView.SpeedAVG.c_str());
    lv_label_set_text(ui_LabelSpeedMax, dataMainView.SpeedMAX.c_str());
    lv_label_set_text(ui_LabelTrip, dataMainView.Trip.c_str());
    lv_label_set_text(ui_LabelTime, dataMainView.Time.c_str());
}


void MainModel::IndevSetup()
{
    lv_group_t* group = lv_group_create();
    lv_group_set_default(group);

    lv_indev_t* cur_drv = NULL;
    for (;;) {
        cur_drv = lv_indev_get_next(cur_drv);
        if (!cur_drv) {
            break;
        }
        if (cur_drv->driver->type == LV_INDEV_TYPE_ENCODER) {
                lv_indev_set_group(cur_drv, group);
        }
        if (cur_drv->driver->type == LV_INDEV_TYPE_POINTER) {
                lv_indev_set_group(cur_drv, group);
        }
    }

    /* Add obi to group */
    lv_group_add_obj(group, ui_ButtonStart);
}


void MainModel::UpdateSport()
{
    /* Every 1s */
    SportTick++;
    if (SportTick < 2)
        return;
    SportTick = 0;
    
    /* If sport mode started */
    if (buttonStartState && HAL::GPS_LocationIsValid() && (gps_info.speed != 0)) {

        /* Update Time */
        /* Every second */
        dataMainModel.Time_s += 1;
        /* Every minute */
        if (dataMainModel.Time_s == 60) {
            dataMainModel.Time_s = 0;
            dataMainModel.Time_m += 1;
            /* Every hour */
            if (dataMainModel.Time_m == 60) {
                dataMainModel.Time_m = 0;
                dataMainModel.Time_h += 1;
            }
        }

        /* Update Speed MAX */
        if (dataMainModel.Speed > dataMainModel.SpeedMAX)
            dataMainModel.SpeedMAX = dataMainModel.Speed;

        /* Update Trip */
        if (dataMainModel.preLong != 0)
            dataMainModel.Trip += HAL::GPS_GetDistanceOffset(&gps_info, dataMainModel.preLong, dataMainModel.preLat) / 1000.0f;
        dataMainModel.preLong = gps_info.longitude;
        dataMainModel.preLat = gps_info.latitude;

        /* Update Speed AVG */
        float Time_m_temp = (float)dataMainModel.Time_m / 60.0f;
        float Time_s_temp = (float)dataMainModel.Time_s / 3600.0f;
        dataMainModel.SpeedAVG = dataMainModel.Trip / ((float)dataMainModel.Time_h + Time_m_temp + Time_s_temp);
    } else {
        dataMainModel.preLong = 0;
        dataMainModel.preLat = 0;
    }
}