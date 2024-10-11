#include "sensors.hpp"
#include <cmath>
// #include "DigitalSensors.hpp"

// static DigitalSensors digital_sensors;
// static uint8_t sensors_reading[num_sensors];
static SensorReading readings;

void set_last_seen(SensorSide side){
    readings.last_seen = side;
}

SensorSide get_last_seen(){
    return readings.last_seen;
}

void sensors_setup() {
    // digital_sensors.setSensorPins(sensors_pins, num_sensors);
    // digital_sensors.setInvertedSensors();
    pinMode(LEFT_ANALOG_SENSOR, INPUT);
    pinMode(LEFT_CENTER_ANALOG_SENSOR, INPUT);
    pinMode(RIGHT_CENTER_ANALOG_SENSOR, INPUT);
    pinMode(RIGHT_ANALOG_SENSOR, INPUT);

    readings.left = 0;
    readings.left_center = 0;
    readings.right_center = 0;
    readings.right = 0;
    readings.last_seen = LEFT_SENSOR;
}

void read_sensors() {
    // digital_sensors.read(sensors_reading);
    readings.left = map_sensor_value(analogRead(LEFT_ANALOG_SENSOR));
    readings.left_center = map_sensor_value(analogRead(LEFT_CENTER_ANALOG_SENSOR));
    readings.right_center = map_sensor_value(analogRead(RIGHT_CENTER_ANALOG_SENSOR));
    readings.right = map_sensor_value(analogRead(RIGHT_ANALOG_SENSOR));
}

uint16_t get_sensor_reading(SensorSide side) {
    if (side == LEFT_SENSOR) {
        return readings.left;
    } else if (side == LEFT_CENTER_SENSOR) {
        return readings.left_center;
    } else if (side == RIGHT_CENTER_SENSOR) {
        return readings.right_center;
    } else { // side == RIGHT
        return readings.right;
    }
}

uint16_t map_sensor_value(int sensor_value) {
    //return floor(sensor_value * 5 / 1980);  // Converte de 0 a 2200 para 0 (perto) a 5 (longe)
    return sensor_value; 
    /*
    0: 0 - <396 (~ até 9cm)
    1: 396 - <792 (~ até 18cm)
    2: 792 - <1188 (~ até 27cm)
    3: 1188 - <1584 (~ até 36cm)
    4: 1584 - <1980 (~ até 45cm)
    5: 1180 - <2376 (~ até 54cm)
    */
}

void print_sensors() {
    Serial.print(readings.left);
    Serial.print(" | ");
    Serial.print(readings.left_center);
    Serial.print(" | ");
    Serial.print(readings.right_center);
    Serial.print(" | ");
    Serial.println(readings.right);
}