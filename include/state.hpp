#pragma once
#include <Arduino.h>

typedef enum{
    SEARCH,
    RIGHT_CENTER_FOLLOW,
    LEFT_CENTER_FOLLOW, 
    CENTER_FOLLOW,
    LEFT_FOLLOW,
    RIGHT_FOLLOW,
    FAILSAFE,
    ATTACK,
    BACK_LINE,
    LEFT_LINE,
    RIGHT_LINE,
    PERTINHO,
    INITIAL_ROUTINE
}States_t;

States_t save_state();
void set_state(States_t new_state);
void decide_state();
void run_state();