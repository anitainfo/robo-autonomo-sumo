#pragma once
#include "Kuroneko.hpp"
#include <stdint.h>

typedef enum {
    LEFT_SENSOR,
    LEFT_CENTER_SENSOR,
    RIGHT_CENTER_SENSOR,
    RIGHT_SENSOR
} SensorSide;

typedef struct _SensorReading {
    uint16_t left, left_center, right_center, right;
    SensorSide last_seen;
} SensorReading;

void sensors_setup();

void read_sensors();

void set_last_seen(SensorSide side);

SensorSide get_last_seen();

uint16_t get_sensor_reading(SensorSide side);

uint16_t map_sensor_value(int sensor_value);

void print_sensors();

const uint8_t num_sensors = 5;
// const uint8_t sensors_pins[num_sensors] = { LEFT_DIGITAL_SENSOR, RIGHT_DIGITAL_SENSOR };