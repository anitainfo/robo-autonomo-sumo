#include "line_sensor.hpp"
#include "Kuroneko.hpp"

line_sensors sensors;

void setup_line_sensors(){
    pinMode(LEFT_LINE_SENSOR, INPUT);              //TROCAR PELOS PINOS DOS IRs
    pinMode(RIGHT_LINE_SENSOR, INPUT);              //TROCAR PELOS PINOS DOS IRs
}

void read_line_sensors(){
    if(analogRead(LEFT_LINE_SENSOR) > LINE_VALUE){
        sensors.left = 1;
    }else{
        sensors.left = 0;
    }
    if(analogRead(RIGHT_LINE_SENSOR) > LINE_VALUE){
        sensors.left = 1;
    }else{
        sensors.left = 0;
    }
}

uint8_t get_line_sensor_reading(Side_line_sensor side){
    if(side == LEFT_SENSOR_STATE) return sensors.left;
    else return sensors.right;
}