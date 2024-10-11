#include <Arduino.h>
#include <stdint.h>

#define LINE_VALUE 1000

typedef struct{
    uint8_t left;
    uint8_t right;
}line_sensors;

typedef enum {
    LEFT_SENSOR_STATE,
    RIGHT_SENSOR_STATE
}Side_line_sensor;

void setup_line_sensors();

void read_line_sensors();

uint8_t get_line_sensor_reading(Side_line_sensor side);