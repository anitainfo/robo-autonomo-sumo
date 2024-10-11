#pragma once

#include "Kuroneko.hpp"

typedef enum {
    SEARCH,
    LEFT_LINE_MANEUVER,
    RIGHT_LINE_MANEUVER,
    BACK_LINE_MANEUVER,
    LEFT_SENSOR_TRIGGERED,
    LEFT_CENTER_SENSOR_TRIGGERED,
    CENTER_SENSOR_TRIGGERED,
    RIGHT_CENTER_SENSOR_TRIGGERED,
    RIGHT_SENSOR_TRIGGERED,
    FAILSAFE_HALT
} KuronekoStrategyState;

typedef enum {
    AWAITING_INPUT = 0,
    CHARGE_RIGHT,
    CHARGE_LEFT,
    CHARGE,
    DRAW,
    RIGHT_FRONT_DRIBBLE,
    LEFT_FRONT_DRIBBLE,
    NONE,
} KuronekoStartingMove;

KuronekoStartingMove get_starting_routine();

void set_starting_routine(KuronekoStartingMove move);

void set_bandeira_open(bool open);

void set_bandeira_side(bool side);

void run_starting_routine();

void set_state(KuronekoStrategyState new_state);

KuronekoStrategyState get_state();

void update_robot_state();

void run_state();