#pragma once
#include <Arduino.h>

#define LEFT_MOTOR_1 35
#define LEFT_MOTOR_2 36
#define RIGHT_MOTOR_1 37
#define RIGHT_MOTOR_2 38
#define MAX_PWR 255

typedef enum{
    RIGHT = 0,
    LEFT,
}Side_t;

void motor_setup();                                 // auto
void motor_control(Side_t side, int16_t speed);

