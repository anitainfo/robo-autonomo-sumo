#pragma once
#include <Arduino.h>

#define SENSOR_LEFT_PIN 17
#define SENSOR_LEFT_CENTER_PIN 18
#define SENSOR_RIGHT_CENTER_PIN 6
#define SENSOR_RIGHT_PIN 5

typedef enum{
    LEFT_SENSOR = 0,
    LEFT_CENTER_SENSOR,
    RIGHT_CENTER_SENSOR,
    RIGHT_SENSOR,
}Side_presence_sensor_t;

typedef struct _SensorReading {
    uint16_t left, left_center, right_center, right;
    Side_presence_sensor_t last_seen;
} SensorReading;

void presence_sensor_setup();
void update_presence_sensor();
void set_last_seen(Side_presence_sensor_t side);

Side_presence_sensor_t get_last_seen();
uint16_t get_presence_sensor(Side_presence_sensor_t side);

void print_sensors();