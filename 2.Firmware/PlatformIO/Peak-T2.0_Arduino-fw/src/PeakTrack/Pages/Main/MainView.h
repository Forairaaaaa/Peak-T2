// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: Peak-Track

#ifndef MAINVIEW_H
#define MAINVIEW_H

// #ifdef __cplusplus
// extern "C" {
// #endif

#include "MainPage.h"

#if __has_include("lvgl.h")
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

extern lv_obj_t * ui_ScreenMAIN;
extern lv_obj_t * ui_Panel;
extern lv_obj_t * ui_LabelClock;
extern lv_obj_t * ui_LabelSpeed;
extern lv_obj_t * ui_LabelSpeedUnit;
extern lv_obj_t * ui_IconSatellite;
extern lv_obj_t * ui_LabelSatellite;
extern lv_obj_t * ui_PanelBattery;
extern lv_obj_t * ui_IconBattery;
extern lv_obj_t * ui_LabelBattery;
extern lv_obj_t * ui_LabelTime;
extern lv_obj_t * ui_LabelTimelabel;
extern lv_obj_t * ui_LabelSpeedAVGlabel;
extern lv_obj_t * ui_LabelSpeedAVG;
extern lv_obj_t * ui_LabelTrip;
extern lv_obj_t * ui_LabelTripLabel;
extern lv_obj_t * ui_LabelSpeedMax;
extern lv_obj_t * ui_LabelSpeedMaxLabel;
extern lv_obj_t * ui_ButtonStart;
extern lv_obj_t * ui_ImgButtonStart;
extern lv_obj_t * ui_ButtonMap;
extern lv_obj_t * ui_ImageMap;
extern lv_obj_t * ui_ButtonMenu;
extern lv_obj_t * ui_Image12;

extern bool buttonStartState;

// LV_IMG_DECLARE(ui_img_artdesign_satellite_png);    // assets\ArtDesign\Satellite.png
// LV_IMG_DECLARE(ui_img_artdesign_bettray_png);    // assets\ArtDesign\bettray.png
// LV_IMG_DECLARE(ui_img_artdesign_start_png);    // assets\ArtDesign\start.png
// LV_IMG_DECLARE(ui_img_artdesign_pause_png);    // assets\ArtDesign\pause.png
// LV_IMG_DECLARE(ui_img_artdesign_locate_png);    // assets\ArtDesign\locate.png
// LV_IMG_DECLARE(ui_img_artdesign_menu_png);    // assets\ArtDesign\menu.png


// LV_FONT_DECLARE(ui_font_bahnschrift_13);
// LV_FONT_DECLARE(ui_font_bahnschrift_17);
// LV_FONT_DECLARE(ui_font_bahnschrift_32);
// LV_FONT_DECLARE(ui_font_bahnschrift_65);


void ui_init(void);

// #ifdef __cplusplus
// } /*extern "C"*/
// #endif

#endif
