/**
 * @file Kuroneko.hpp
 * @author Gustavo Palma (gustavolpalma@gmail.com)
 * @author Gabriella Tomoda
 * @author Eduardo Schroeder
 * @brief 
 * @version 1.0
 * @date 2023-03-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#include <Arduino.h>
#include <stdint.h>

#define IR_SENSOR 47

#define LEFT_ANALOG_SENSOR 6
#define LEFT_CENTER_ANALOG_SENSOR 5
#define RIGHT_CENTER_ANALOG_SENSOR 17
#define RIGHT_ANALOG_SENSOR 18

#define RIGHT_MOTOR_1 37        //RIGHT
#define RIGHT_MOTOR_2 38

#define LEFT_MOTOR_1 35           //LEFT
#define LEFT_MOTOR_2 36

#define LEFT_LINE_SENSOR A6
#define RIGHT_LINE_SENSOR A7

// #define RC_RECEIVER_1 6
// #define RC_RECEIVER_2 9

void print_introduction();
