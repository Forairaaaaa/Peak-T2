// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.0.5
// LVGL VERSION: 8.2
// PROJECT: Peak-Track

#include "MainView.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_ScreenMAIN;
lv_obj_t * ui_Panel;
lv_obj_t * ui_LabelClock;
lv_obj_t * ui_LabelSpeed;
lv_obj_t * ui_LabelSpeedUnit;
lv_obj_t * ui_IconSatellite;
lv_obj_t * ui_LabelSatellite;
lv_obj_t * ui_PanelBattery;
lv_obj_t * ui_IconBattery;
lv_obj_t * ui_LabelBattery;
lv_obj_t * ui_LabelTime;
lv_obj_t * ui_LabelTimelabel;
lv_obj_t * ui_LabelSpeedAVGlabel;
lv_obj_t * ui_LabelSpeedAVG;
lv_obj_t * ui_LabelTrip;
lv_obj_t * ui_LabelTripLabel;
lv_obj_t * ui_LabelSpeedMax;
lv_obj_t * ui_LabelSpeedMaxLabel;
lv_obj_t * ui_ButtonStart;
lv_obj_t * ui_ImgButtonStart;
lv_obj_t * ui_ButtonMap;
lv_obj_t * ui_ImageMap;
lv_obj_t * ui_ButtonMenu;
lv_obj_t * ui_Image12;


/* User */
bool buttonStartState = false;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "#error LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
static void ui_event_ButtonStart(lv_event_t * e)
{
    lv_event_code_t event = lv_event_get_code(e);
    // lv_obj_t * ta = lv_event_get_target(e);

    if(event == LV_EVENT_CLICKED) {
        buttonStartState = buttonStartState ? false : true;
        if (buttonStartState) {
            // lv_label_set_text(ui_LabelBattery, "Y");
            ui_ImgButtonStart->state = LV_STATE_CHECKED;
        } else {
            // lv_label_set_text(ui_LabelBattery, "N");
            ui_ImgButtonStart->state = LV_STATE_DEFAULT;
        }
    }
}
static void ui_event_ButtonMap(lv_event_t * e)
{
    // lv_event_code_t event = lv_event_get_code(e);
    // lv_obj_t * ta = lv_event_get_target(e);
}
static void ui_event_ButtonMenu(lv_event_t * e)
{
    // lv_event_code_t event = lv_event_get_code(e);
    // lv_obj_t * ta = lv_event_get_target(e);
}

///////////////////// SCREENS ////////////////////
void ui_ScreenMAIN_screen_init(void)
{

    // ui_ScreenMAIN

    ui_ScreenMAIN = lv_obj_create(NULL);

    lv_obj_clear_flag(ui_ScreenMAIN, LV_OBJ_FLAG_SCROLLABLE);

    // ui_Panel

    ui_Panel = lv_obj_create(ui_ScreenMAIN);

    lv_obj_set_width(ui_Panel, 240);
    lv_obj_set_height(ui_Panel, 142);

    lv_obj_set_x(ui_Panel, 0);
    lv_obj_set_y(ui_Panel, -93);

    lv_obj_set_align(ui_Panel, LV_ALIGN_CENTER);

    lv_obj_clear_flag(ui_Panel, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);

    // ui_LabelClock

    ui_LabelClock = lv_label_create(ui_ScreenMAIN);

    lv_obj_set_width(ui_LabelClock, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelClock, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelClock, lv_pct(0));
    lv_obj_set_y(ui_LabelClock, lv_pct(-46));

    lv_obj_set_align(ui_LabelClock, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelClock, "21 : 30");

    lv_obj_set_style_text_align(ui_LabelClock, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelClock, &ui_font_bahnschrift_17, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelSpeed

    ui_LabelSpeed = lv_label_create(ui_ScreenMAIN);

    lv_obj_set_width(ui_LabelSpeed, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelSpeed, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelSpeed, lv_pct(0));
    lv_obj_set_y(ui_LabelSpeed, lv_pct(-29));

    lv_obj_set_align(ui_LabelSpeed, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelSpeed, "00");

    lv_obj_set_style_text_align(ui_LabelSpeed, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelSpeed, &ui_font_bahnschrift_65, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelSpeedUnit

    ui_LabelSpeedUnit = lv_label_create(ui_ScreenMAIN);

    lv_obj_set_width(ui_LabelSpeedUnit, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelSpeedUnit, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelSpeedUnit, lv_pct(0));
    lv_obj_set_y(ui_LabelSpeedUnit, lv_pct(-16));

    lv_obj_set_align(ui_LabelSpeedUnit, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelSpeedUnit, "km/h");

    lv_obj_set_style_text_align(ui_LabelSpeedUnit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelSpeedUnit, &ui_font_bahnschrift_17, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_IconSatellite

    ui_IconSatellite = lv_img_create(ui_ScreenMAIN);
    lv_img_set_src(ui_IconSatellite, &ui_img_artdesign_satellite_png);

    lv_obj_set_width(ui_IconSatellite, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_IconSatellite, LV_SIZE_CONTENT);

    lv_obj_set_y(ui_IconSatellite, -148);
    lv_obj_set_x(ui_IconSatellite, lv_pct(-44));

    lv_obj_set_align(ui_IconSatellite, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_IconSatellite, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_IconSatellite, LV_OBJ_FLAG_SCROLLABLE);

    // ui_LabelSatellite

    ui_LabelSatellite = lv_label_create(ui_ScreenMAIN);

    lv_obj_set_width(ui_LabelSatellite, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelSatellite, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelSatellite, -82);
    lv_obj_set_y(ui_LabelSatellite, -147);

    lv_obj_set_align(ui_LabelSatellite, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelSatellite, "27");

    lv_obj_set_style_text_align(ui_LabelSatellite, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelSatellite, &ui_font_bahnschrift_17, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_PanelBattery

    ui_PanelBattery = lv_obj_create(ui_ScreenMAIN);

    lv_obj_set_width(ui_PanelBattery, 10);
    lv_obj_set_height(ui_PanelBattery, 12);

    lv_obj_set_x(ui_PanelBattery, 86);
    lv_obj_set_y(ui_PanelBattery, -298);

    lv_obj_set_align(ui_PanelBattery, LV_ALIGN_BOTTOM_MID);

    lv_obj_clear_flag(ui_PanelBattery, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_set_style_radius(ui_PanelBattery, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_PanelBattery, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelBattery, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_IconBattery

    ui_IconBattery = lv_img_create(ui_ScreenMAIN);
    lv_img_set_src(ui_IconBattery, &ui_img_artdesign_bettray_png);

    lv_obj_set_width(ui_IconBattery, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_IconBattery, LV_SIZE_CONTENT);

    lv_obj_set_y(ui_IconBattery, -148);
    lv_obj_set_x(ui_IconBattery, lv_pct(36));

    lv_obj_set_align(ui_IconBattery, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_IconBattery, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_IconBattery, LV_OBJ_FLAG_SCROLLABLE);

    // ui_LabelBattery

    ui_LabelBattery = lv_label_create(ui_ScreenMAIN);

    lv_obj_set_width(ui_LabelBattery, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelBattery, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelBattery, 103);
    lv_obj_set_y(ui_LabelBattery, -147);

    lv_obj_set_align(ui_LabelBattery, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelBattery, "86");

    lv_obj_set_style_text_align(ui_LabelBattery, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelBattery, &ui_font_bahnschrift_17, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelTime

    ui_LabelTime = lv_label_create(ui_ScreenMAIN);

    lv_obj_set_width(ui_LabelTime, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelTime, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelTime, lv_pct(24));
    lv_obj_set_y(ui_LabelTime, lv_pct(16));

    lv_obj_set_align(ui_LabelTime, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelTime, "00:00:00");

    lv_obj_set_style_text_align(ui_LabelTime, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTime, &ui_font_bahnschrift_17, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelTimelabel

    ui_LabelTimelabel = lv_label_create(ui_ScreenMAIN);

    lv_obj_set_width(ui_LabelTimelabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelTimelabel, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelTimelabel, lv_pct(24));
    lv_obj_set_y(ui_LabelTimelabel, lv_pct(24));

    lv_obj_set_align(ui_LabelTimelabel, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelTimelabel, "Time");

    lv_obj_set_style_text_color(ui_LabelTimelabel, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTimelabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelTimelabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTimelabel, &ui_font_bahnschrift_17, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelSpeedAVGlabel

    ui_LabelSpeedAVGlabel = lv_label_create(ui_ScreenMAIN);

    lv_obj_set_width(ui_LabelSpeedAVGlabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelSpeedAVGlabel, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelSpeedAVGlabel, lv_pct(-24));
    lv_obj_set_y(ui_LabelSpeedAVGlabel, lv_pct(8));

    lv_obj_set_align(ui_LabelSpeedAVGlabel, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelSpeedAVGlabel, "AVG");

    lv_obj_set_style_text_color(ui_LabelSpeedAVGlabel, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelSpeedAVGlabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelSpeedAVGlabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelSpeedAVGlabel, &ui_font_bahnschrift_17, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelSpeedAVG

    ui_LabelSpeedAVG = lv_label_create(ui_ScreenMAIN);

    lv_obj_set_width(ui_LabelSpeedAVG, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelSpeedAVG, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelSpeedAVG, lv_pct(-24));
    lv_obj_set_y(ui_LabelSpeedAVG, lv_pct(0));

    lv_obj_set_align(ui_LabelSpeedAVG, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelSpeedAVG, "00 km/h");

    lv_obj_set_style_text_align(ui_LabelSpeedAVG, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelSpeedAVG, &ui_font_bahnschrift_17, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelTrip

    ui_LabelTrip = lv_label_create(ui_ScreenMAIN);

    lv_obj_set_width(ui_LabelTrip, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelTrip, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelTrip, lv_pct(-24));
    lv_obj_set_y(ui_LabelTrip, lv_pct(16));

    lv_obj_set_align(ui_LabelTrip, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelTrip, "00 km");

    lv_obj_set_style_text_align(ui_LabelTrip, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTrip, &ui_font_bahnschrift_17, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelTripLabel

    ui_LabelTripLabel = lv_label_create(ui_ScreenMAIN);

    lv_obj_set_width(ui_LabelTripLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelTripLabel, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelTripLabel, lv_pct(-24));
    lv_obj_set_y(ui_LabelTripLabel, lv_pct(24));

    lv_obj_set_align(ui_LabelTripLabel, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelTripLabel, "Trip");

    lv_obj_set_style_text_color(ui_LabelTripLabel, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelTripLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelTripLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelTripLabel, &ui_font_bahnschrift_17, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelSpeedMax

    ui_LabelSpeedMax = lv_label_create(ui_ScreenMAIN);

    lv_obj_set_width(ui_LabelSpeedMax, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelSpeedMax, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelSpeedMax, lv_pct(24));
    lv_obj_set_y(ui_LabelSpeedMax, lv_pct(0));

    lv_obj_set_align(ui_LabelSpeedMax, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelSpeedMax, "00 km/h");

    lv_obj_set_style_text_align(ui_LabelSpeedMax, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelSpeedMax, &ui_font_bahnschrift_17, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_LabelSpeedMaxLabel

    ui_LabelSpeedMaxLabel = lv_label_create(ui_ScreenMAIN);

    lv_obj_set_width(ui_LabelSpeedMaxLabel, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_LabelSpeedMaxLabel, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_LabelSpeedMaxLabel, lv_pct(24));
    lv_obj_set_y(ui_LabelSpeedMaxLabel, lv_pct(8));

    lv_obj_set_align(ui_LabelSpeedMaxLabel, LV_ALIGN_CENTER);

    lv_label_set_text(ui_LabelSpeedMaxLabel, "MAX");

    lv_obj_set_style_text_color(ui_LabelSpeedMaxLabel, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LabelSpeedMaxLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_LabelSpeedMaxLabel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LabelSpeedMaxLabel, &ui_font_bahnschrift_17, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_ButtonStart

    ui_ButtonStart = lv_btn_create(ui_ScreenMAIN);

    lv_obj_set_width(ui_ButtonStart, 40);
    lv_obj_set_height(ui_ButtonStart, 30);

    lv_obj_set_x(ui_ButtonStart, 0);
    lv_obj_set_y(ui_ButtonStart, 120);

    lv_obj_set_align(ui_ButtonStart, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonStart, LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonStart, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonStart, ui_event_ButtonStart, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonStart, lv_color_hex(0x515151), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonStart, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonStart, lv_color_hex(0xF4AA56), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_ButtonStart, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    // ui_ImgButtonStart

    ui_ImgButtonStart = lv_imgbtn_create(ui_ScreenMAIN);
    lv_imgbtn_set_src(ui_ImgButtonStart, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_artdesign_start_png, NULL);
    lv_imgbtn_set_src(ui_ImgButtonStart, LV_IMGBTN_STATE_PRESSED, NULL, &ui_img_artdesign_start_png, NULL);
    lv_imgbtn_set_src(ui_ImgButtonStart, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &ui_img_artdesign_pause_png, NULL);
    lv_imgbtn_set_src(ui_ImgButtonStart, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &ui_img_artdesign_pause_png, NULL);

    lv_obj_set_height(ui_ImgButtonStart, 15);
    lv_obj_set_width(ui_ImgButtonStart, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ImgButtonStart, 0);
    lv_obj_set_y(ui_ImgButtonStart, 120);

    lv_obj_set_align(ui_ImgButtonStart, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ImgButtonStart, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_clear_flag(ui_ImgButtonStart, LV_OBJ_FLAG_CLICKABLE);

    // ui_ButtonMap

    ui_ButtonMap = lv_btn_create(ui_ScreenMAIN);

    lv_obj_set_width(ui_ButtonMap, 40);
    lv_obj_set_height(ui_ButtonMap, 30);

    lv_obj_set_x(ui_ButtonMap, -80);
    lv_obj_set_y(ui_ButtonMap, 120);

    lv_obj_set_align(ui_ButtonMap, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonMap, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonMap, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonMap, ui_event_ButtonMap, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonMap, lv_color_hex(0x525052), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonMap, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonMap, lv_color_hex(0x525052), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_ButtonMap, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    // ui_ImageMap

    ui_ImageMap = lv_img_create(ui_ScreenMAIN);
    lv_img_set_src(ui_ImageMap, &ui_img_artdesign_locate_png);

    lv_obj_set_width(ui_ImageMap, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_ImageMap, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_ImageMap, -80);
    lv_obj_set_y(ui_ImageMap, 120);

    lv_obj_set_align(ui_ImageMap, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ImageMap, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_ImageMap, LV_OBJ_FLAG_SCROLLABLE);

    // ui_ButtonMenu

    ui_ButtonMenu = lv_btn_create(ui_ScreenMAIN);

    lv_obj_set_width(ui_ButtonMenu, 40);
    lv_obj_set_height(ui_ButtonMenu, 30);

    lv_obj_set_x(ui_ButtonMenu, 80);
    lv_obj_set_y(ui_ButtonMenu, 120);

    lv_obj_set_align(ui_ButtonMenu, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_ButtonMenu, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_clear_flag(ui_ButtonMenu, LV_OBJ_FLAG_SCROLLABLE);

    lv_obj_add_event_cb(ui_ButtonMenu, ui_event_ButtonMenu, LV_EVENT_ALL, NULL);
    lv_obj_set_style_bg_color(ui_ButtonMenu, lv_color_hex(0x525052), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonMenu, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ButtonMenu, lv_color_hex(0x525052), LV_PART_MAIN | LV_STATE_CHECKED);
    lv_obj_set_style_bg_opa(ui_ButtonMenu, 255, LV_PART_MAIN | LV_STATE_CHECKED);

    // ui_Image12

    ui_Image12 = lv_img_create(ui_ScreenMAIN);
    lv_img_set_src(ui_Image12, &ui_img_artdesign_menu_png);

    lv_obj_set_width(ui_Image12, LV_SIZE_CONTENT);
    lv_obj_set_height(ui_Image12, LV_SIZE_CONTENT);

    lv_obj_set_x(ui_Image12, 80);
    lv_obj_set_y(ui_Image12, 120);

    lv_obj_set_align(ui_Image12, LV_ALIGN_CENTER);

    lv_obj_add_flag(ui_Image12, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(ui_Image12, LV_OBJ_FLAG_SCROLLABLE);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_ScreenMAIN_screen_init();
    lv_disp_load_scr(ui_ScreenMAIN);
}

