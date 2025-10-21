#pragma once
#define INFRARED_PIN 47

// utiliza timer 2 do nano para não interferir com a função 
// motor_control que usa timer 2 no analog write

typedef enum {
   BTTN_1 = 0x00,
   BTTN_2,
   BTTN_3,
   BTTN_4,
   BTTN_5,
   BTTN_6,
   BTTN_7,
   BTTN_8,
   BTTN_9,
   BTTN_0 = 0x9,
   BTTN_OK = 0x65,
   BTTN_ARROW_LEFT = 0x34,
   BTTN_ARROW_RIGHT = 0x33,
   BTTN_ARROW_UP = 0x74,
   BTTN_ARROW_DOWN = 0x75,
   BTTN_DIGITAL = 0xD,
   BTTN_EXIT = 0x63,
   BTTN_TV = 0x57,
   BTTN_GUIDE = 0xA4,
   BTTN_INFORMATION = 0x1,
   BTTN_RED_SQUARE = 0x25
}SonyControllerButton_t;


typedef enum {
   OK_BUTTON                   = BTTN_OK,
   RADIO_CONTROL_BUTTON        = BTTN_0,
   BLINK_BUTTON                = BTTN_1,
   FIGHT_START_BUTTON          = BTTN_2,
   STOP_BUTTON                 = BTTN_3,
   LEFT_HALFMOON_BUTTON        = BTTN_4,
   RIGHT_HALFMOON_BUTTON       = BTTN_6,
   LEFT_CHARGE_BUTTON          = BTTN_7,
   RIGHT_CHARGE_BUTTON         = BTTN_9,
   CHARGE_BUTTON               = BTTN_ARROW_UP,
   DRAW_BUTTON                 = BTTN_ARROW_DOWN,
   SELECT_LEFT_BUTTON          = BTTN_ARROW_LEFT,
   SELECT_RIGHT_BUTTON         = BTTN_ARROW_RIGHT,
   LEFT_DRIBBLE_BUTTON         = BTTN_DIGITAL,
   RIGHT_DRIBBLE_BUTTON        = BTTN_TV,
   DONT_STOP_INI_ROT_BUTTON   = BTTN_RED_SQUARE
} InicialControllerButtons_t;

void infrared_setup();
void wait_referee_signal();
void define_initial_routine();
void check_for_failsafe_signal();