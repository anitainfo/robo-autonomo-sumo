#include "presence_sensor.hpp"

static SensorReading readings;

void set_last_seen(Side_presence_sensor_t side){
    readings.last_seen = side;
}

Side_presence_sensor_t get_last_seen(){
    return readings.last_seen;
}

void presence_sensor_setup(){
    pinMode(SENSOR_LEFT_PIN, INPUT);
    pinMode(SENSOR_LEFT_CENTER_PIN, INPUT);
    pinMode(SENSOR_RIGHT_CENTER_PIN, INPUT);
    pinMode(SENSOR_RIGHT_PIN, INPUT);

    readings.left = 0;
    readings.left_center = 0;
    readings.right_center = 0;
    readings.right = 0;
    readings.last_seen = LEFT_SENSOR;
}

void update_presence_sensor(){
    readings.left = analogRead(SENSOR_LEFT_PIN);
    readings.left_center = analogRead(SENSOR_LEFT_CENTER_PIN);
    readings.right_center = analogRead(SENSOR_RIGHT_CENTER_PIN);
    readings.right = analogRead(SENSOR_RIGHT_PIN);
}

uint16_t get_presence_sensor(Side_presence_sensor_t side){
    if (side == LEFT_SENSOR){
        return readings.left;
    }
    if (side == LEFT_CENTER_SENSOR){
        return readings.left_center;
    }
    else if(side == RIGHT_CENTER_SENSOR){
        return readings.right_center;
    }
    else {
        return readings.right;
    }
}

void print_sensors(){
    Serial.print(readings.left);
    Serial.print(" | ");
    Serial.print(readings.left_center);
    Serial.print(" | ");
    Serial.print(readings.right_center);
    Serial.print(" | ");
    Serial.println(readings.right);
    delay(100);
}