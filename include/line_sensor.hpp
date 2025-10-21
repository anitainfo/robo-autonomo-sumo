#pragma once
#include <Arduino.h>

#define LINE_VALUE 700
#define LEFT_LINE_SENSOR_PIN A5
#define RIGHT_LINE_SENSOR_PIN A4

typedef struct{
    uint8_t left, right;
}ReadingLineSensor;

typedef enum {
    LEFT_LINE_SENSOR,
    RIGHT_LINE_SENSOR
}Side_line_sensor_t;

void line_sensors_setup();
void read_line_sensors();
uint8_t get_line_sensor_reading(Side_line_sensor_t side);