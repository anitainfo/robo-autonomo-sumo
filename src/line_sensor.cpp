#include "line_sensor.hpp"

static ReadingLineSensor sensors;

void line_sensors_setup(){
    pinMode(LEFT_LINE_SENSOR_PIN, INPUT);             
    pinMode(RIGHT_LINE_SENSOR_PIN, INPUT);              
}

void read_line_sensors(){
    sensors.left = analogRead(LEFT_LINE_SENSOR_PIN);
    sensors.right = analogRead(RIGHT_LINE_SENSOR_PIN);
    // Serial.begin(9600);
    // Serial.print(sensors.left); 
    // Serial.print("\t"); 
    // Serial.println(sensors.right); 
}

uint8_t get_line_sensor_reading(Side_line_sensor_t side){
    if(side == LEFT_LINE_SENSOR){
        return sensors.left;
    }
    else if(side == RIGHT_LINE_SENSOR){
        return sensors.right;
    }
}