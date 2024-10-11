/**
 * @file infrared.hpp
 * @author Gabriella Tomoda (gabriellasmt@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-03-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once
#define DECODE_SONY

#include "Kuroneko.hpp"

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
    BTTN_0,
    BTTN_OK = 0x65,
    BTTN_ARROW_LEFT = 0x34,
    BTTN_ARROW_RIGHT = 0x33,
    BTTN_ARROW_UP = 0x74,
    BTTN_ARROW_DOWN = 0x75,
    BTTN_GUIDE = 0xA4,
    BTTN_INFORMATION = 0x1
} SonyControllerButton;

typedef enum {
    BLINK_BUTTON                = BTTN_1,
    FIGHT_START_BUTTON          = BTTN_2,
    STOP_BUTTON                 = BTTN_3,
    DRAW_BUTTON                 = BTTN_ARROW_DOWN,
    CHARGE_BUTTON               = BTTN_ARROW_UP,
    CHARGE_LEFT_BUTTON          = BTTN_4,
    CHARGE_RIGHT_BUTTON         = BTTN_6,
    LEFT_START_BUTTON           = BTTN_ARROW_LEFT,
    RIGHT_START_BUTTON          = BTTN_ARROW_RIGHT,
    OK_BUTTON                   = BTTN_OK,
    RADIO_CONTROL_BUTTON        = BTTN_0,
    RIGHT_FRONT_DRIBBLE_BUTTON  = BTTN_INFORMATION,
    LEFT_FRONT_DRIBBLE_BUTTON   = BTTN_GUIDE
} KuronekoControllerButtons;

void infrared_setup();

void define_starting_routine();

void wait_referee_signal(void);

void check_for_failsafe_signal(void);
