#pragma once
#include <Arduino.h>

typedef enum{
    CHARGE = 0, 
    DRAW,
    LEFT_HALFMOON,
    RIGHT_HALFMOON,
    LEFT_CHARGE,
    RIGHT_CHARGE,
    LEFT_DRIBBLE,
    RIGHT_DRIBBLE,
    SELECT_LEFT,
    SELECT_RIGHT,
    RADIO_CONTROL,
    DONT_STOP_INI_ROT,
    NONE
}Initial_routine_t;

//Initial_routine_t save_initial_routine();
void set_initial_routine(Initial_routine_t move);
void run_initial_routine();
void set_is_running(bool new_is_running);

bool get_is_running();