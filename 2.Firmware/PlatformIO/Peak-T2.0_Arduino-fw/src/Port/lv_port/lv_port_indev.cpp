/**
 * @file lv_port_indev_templ.c
 *
 */

 /*Copy this file as "lv_port_indev.c" and set this value to "1" to enable content*/
#if 1

/*********************
 *      INCLUDES
 *********************/
#include "lvgl.h"
#include "HAL/HAL.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/* Task for keys' reading */
// void keysRead( void *pvParameters );
/* Key state */
// static uint32_t keyID;
// static uint8_t keyState;

// static void touchpad_init(void);
static void touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
// static bool touchpad_is_pressed(void);
// static void touchpad_get_xy(lv_coord_t * x, lv_coord_t * y);

// static void mouse_init(void);
// static void mouse_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
// static bool mouse_is_pressed(void);
// static void mouse_get_xy(lv_coord_t * x, lv_coord_t * y);

// static void keypad_init(void);
// static void keypad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
// static uint32_t keypad_get_key(void);

// static void encoder_init(void);
static void encoder_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
// static void encoder_handler(void);

// static void button_init(void);
// static void button_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
// static int8_t button_get_pressed_id(void);
// static bool button_is_pressed(uint8_t id);



/**********************
 *  STATIC VARIABLES
 **********************/
lv_indev_t * indev_touchpad;
static TouchPoint_t coordinate;
// lv_indev_t * indev_mouse;
// lv_indev_t * indev_keypad;
lv_indev_t * indev_encoder;
// lv_indev_t * indev_button;

lv_group_t * lv_group;

M5Touch T;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lv_port_indev_init(void)
{
    /**
     * Here you will find example implementation of input devices supported by LittelvGL:
     *  - Touchpad
     *  - Mouse (with cursor support)
     *  - Keypad (supports GUI usage only with key)
     *  - Encoder (supports GUI usage only with: left, right, push)
     *  - Button (external buttons to press points on the screen)
     *
     *  The `..._read()` function are only examples.
     *  You should shape them according to your hardware
     */

    static lv_indev_drv_t indev_drv_Touchpad;
    static lv_indev_drv_t indev_drv_Encoder;

    /*------------------
     * Touchpad
     * -----------------*/

    /*Initialize your touchpad if you have*/
    // touchpad_init();

    /*Register a touchpad input device*/
    lv_indev_drv_init(&indev_drv_Touchpad);
    indev_drv_Touchpad.type = LV_INDEV_TYPE_POINTER;
    indev_drv_Touchpad.read_cb = touchpad_read;
    indev_touchpad = lv_indev_drv_register(&indev_drv_Touchpad);

    /*------------------
     * Mouse
     * -----------------*/

    /*Initialize your touchpad if you have*/
    // mouse_init();

    // /*Register a mouse input device*/
    // lv_indev_drv_init(&indev_drv);
    // indev_drv.type = LV_INDEV_TYPE_POINTER;
    // indev_drv.read_cb = mouse_read;
    // indev_mouse = lv_indev_drv_register(&indev_drv);

    // /*Set cursor. For simplicity set a HOME symbol now.*/
    // lv_obj_t * mouse_cursor = lv_img_create(lv_scr_act());
    // lv_img_set_src(mouse_cursor, LV_SYMBOL_HOME);
    // lv_indev_set_cursor(indev_mouse, mouse_cursor);

    /*------------------
     * Keypad
     * -----------------*/

    /*Initialize your keypad or keyboard if you have*/
    // keypad_init();

    // /*Register a keypad input device*/
    // lv_indev_drv_init(&indev_drv);
    // indev_drv.type = LV_INDEV_TYPE_KEYPAD;
    // indev_drv.read_cb = keypad_read;
    // indev_keypad = lv_indev_drv_register(&indev_drv);

    /*Later you should create group(s) with `lv_group_t * group = lv_group_create()`,
     *add objects to the group with `lv_group_add_obj(group, obj)`
     *and assign this input device to group to navigate in it:
     *`lv_indev_set_group(indev_keypad, group);`*/

    /*------------------
     * Encoder
     * -----------------*/

    /*Initialize your encoder if you have*/
    // encoder_init();

    /*Register a encoder input device*/
    lv_indev_drv_init(&indev_drv_Encoder);
    indev_drv_Encoder.type = LV_INDEV_TYPE_ENCODER;
    indev_drv_Encoder.read_cb = encoder_read;
    indev_encoder = lv_indev_drv_register(&indev_drv_Encoder);

    /*Later you should create group(s) with `lv_group_t * group = lv_group_create()`,
     *add objects to the group with `lv_group_add_obj(group, obj)`
     *and assign this input device to group to navigate in it:
     *`lv_indev_set_group(indev_encoder, group);`*/

    /* Create group */
    // lv_group = lv_group_create();
    // lv_indev_set_group(indev_encoder, lv_group); 


    /*------------------
     * Button
     * -----------------*/

    /*Initialize your button if you have*/
    // button_init();

    // /*Register a button input device*/
    // lv_indev_drv_init(&indev_drv);
    // indev_drv.type = LV_INDEV_TYPE_BUTTON;
    // indev_drv.read_cb = button_read;
    // indev_button = lv_indev_drv_register(&indev_drv);

    // /*Assign buttons to points on the screen*/
    // static const lv_point_t btn_points[2] = {
    //         {10, 10},   /*Button 0 -> x:10; y:10*/
    //         {40, 100},  /*Button 1 -> x:40; y:100*/
    // };
    // lv_indev_set_button_points(indev_button, btn_points);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/*------------------
 * Touchpad
 * -----------------*/

// /*Initialize your touchpad*/
// static void touchpad_init(void)
// {
//     /*Your code comes here*/
// }

/*Will be called by the library to read the touchpad*/
static void touchpad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    // static lv_coord_t last_x = 0;
    // static lv_coord_t last_y = 0;

    // /*Save the pressed coordinates and the state*/
    // if(touchpad_is_pressed()) {
    //     touchpad_get_xy(&last_x, &last_y);
    //     data->state = LV_INDEV_STATE_PR;
    // } else {
    //     data->state = LV_INDEV_STATE_REL;
    // }

    // /*Set the last pressed coordinates*/
    // data->point.x = last_x;
    // data->point.y = last_y;


    /* Read touch point */
    HAL::Touch_GetPressPoint(&coordinate);
    // Serial.printf("x:%d, y:%d \r\n", coordinate.x, coordinate.y);
    if (coordinate.x == -1) {
        data->state = LV_INDEV_STATE_REL;
    } else {
        data->point.x = coordinate.x;
        data->point.y = coordinate.y;
        data->state = LV_INDEV_STATE_PR;
    }
}

// /*Return true is the touchpad is pressed*/
// static bool touchpad_is_pressed(void)
// {
//     /*Your code comes here*/

//     return false;
// }

// /*Get the x and y coordinates if the touchpad is pressed*/
// static void touchpad_get_xy(lv_coord_t * x, lv_coord_t * y)
// {
//     /*Your code comes here*/

//     (*x) = 0;
//     (*y) = 0;
// }

// /*------------------
//  * Mouse
//  * -----------------*/

// /*Initialize your mouse*/
// static void mouse_init(void)
// {
//     /*Your code comes here*/
// }

// /*Will be called by the library to read the mouse*/
// static void mouse_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
// {
//     /*Get the current x and y coordinates*/
//     mouse_get_xy(&data->point.x, &data->point.y);

//     /*Get whether the mouse button is pressed or released*/
//     if(mouse_is_pressed()) {
//         data->state = LV_INDEV_STATE_PR;
//     } else {
//         data->state = LV_INDEV_STATE_REL;
//     }
// }

// /*Return true is the mouse button is pressed*/
// static bool mouse_is_pressed(void)
// {
//     /*Your code comes here*/

//     return false;
// }

// /*Get the x and y coordinates if the mouse is pressed*/
// static void mouse_get_xy(lv_coord_t * x, lv_coord_t * y)
// {
//     /*Your code comes here*/

//     (*x) = 0;
//     (*y) = 0;
// }

// /*------------------
//  * Keypad
//  * -----------------*/

// /*Initialize your keypad*/
// static void keypad_init(void)
// {
//     /*Your code comes here*/
// }

// /*Will be called by the library to read the mouse*/
// static void keypad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
// {
//     static uint32_t last_key = 0;

//     /*Get the current x and y coordinates*/
//     mouse_get_xy(&data->point.x, &data->point.y);

//     /*Get whether the a key is pressed and save the pressed key*/
//     uint32_t act_key = keypad_get_key();
//     if(act_key != 0) {
//         data->state = LV_INDEV_STATE_PR;

//         /*Translate the keys to LVGL control characters according to your key definitions*/
//         switch(act_key) {
//         case 1:
//             act_key = LV_KEY_NEXT;
//             break;
//         case 2:
//             act_key = LV_KEY_PREV;
//             break;
//         case 3:
//             act_key = LV_KEY_LEFT;
//             break;
//         case 4:
//             act_key = LV_KEY_RIGHT;
//             break;
//         case 5:
//             act_key = LV_KEY_ENTER;
//             break;
//         }

//         last_key = act_key;
//     } else {
//         data->state = LV_INDEV_STATE_REL;
//     }

//     data->key = last_key;
// }

// /*Get the currently being pressed key.  0 if no key is pressed*/
// static uint32_t keypad_get_key(void)
// {
//     /*Your code comes here*/

//     return 0;
// }

/*------------------
 * Encoder
 * -----------------*/

/*Initialize your keypad*/
// static void encoder_init(void)
// {

// }


/*Will be called by the library to read the encoder*/
static void encoder_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    data->enc_diff = HAL::Encoder_GetDiff();
    data->state =  HAL::Encoder_GetIsPush() ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL;
}

/*Call this function in an interrupt to process encoder events (turn, press)*/
// static void encoder_handler(void)
// {
//     /*Your code comes here*/
// }

// /*------------------
//  * Button
//  * -----------------*/

// /*Initialize your buttons*/
// static void button_init(void)
// {
//     /*Your code comes here*/
// }

// /*Will be called by the library to read the button*/
// static void button_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
// {

//     static uint8_t last_btn = 0;

//     /*Get the pressed button's ID*/
//     int8_t btn_act = button_get_pressed_id();

//     if(btn_act >= 0) {
//         data->state = LV_INDEV_STATE_PR;
//         last_btn = btn_act;
//     } else {
//         data->state = LV_INDEV_STATE_REL;
//     }

//     /*Save the last pressed button's ID*/
//     data->btn_id = last_btn;
// }

// /*Get ID  (0, 1, 2 ..) of the pressed button*/
// static int8_t button_get_pressed_id(void)
// {
//     uint8_t i;

//     /*Check to buttons see which is being pressed (assume there are 2 buttons)*/
//     for(i = 0; i < 2; i++) {
//         /*Return the pressed button's ID*/
//         if(button_is_pressed(i)) {
//             return i;
//         }
//     }

//     /*No button pressed*/
//     return -1;
// }

// /*Test if `id` button is pressed or not*/
// static bool button_is_pressed(uint8_t id)
// {

//     /*Your code comes here*/

//     return false;
// }

#else /*Enable this file at the top*/

/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif