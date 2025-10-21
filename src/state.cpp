#include "state.hpp"
#include "infrared.hpp"
#include "motors.hpp"
#include "presence_sensor.hpp"
#include "line_sensor.hpp"
#include "initial_routine.hpp"
#include <stdint.h>

static States_t current_state = INITIAL_ROUTINE;

int frente_esq = 1900;
int frente_dir = 1900;
int centro = 1450;
int lateral_esq = 1900;
int lateral_dir = 1800;
uint16_t last_left_sensor = 0;
uint16_t last_left_center_sensor = 0;
uint16_t last_right_center_sensor = 0;
uint16_t last_right_sensor = 0;

void set_state(States_t new_state){
    current_state = new_state;
}                                                                                     

States_t save_state(){
    return current_state;
}

void decide_state(){
    if(save_state() == FAILSAFE) return;

    uint16_t l1 = get_presence_sensor(LEFT_SENSOR); 
    uint16_t l2 = get_presence_sensor(LEFT_SENSOR); 
    uint16_t l3 = get_presence_sensor(LEFT_SENSOR); 
    uint16_t left_sensor = (l1+l2+l3)/3;   
    
    uint16_t lc1 = get_presence_sensor(LEFT_CENTER_SENSOR); 
    uint16_t lc2 = get_presence_sensor(LEFT_CENTER_SENSOR); 
    uint16_t lc3 = get_presence_sensor(LEFT_CENTER_SENSOR); 
    uint16_t left_center_sensor = (lc1+lc2+lc3)/3;

    uint16_t rc1 = get_presence_sensor(RIGHT_CENTER_SENSOR); 
    uint16_t rc2 = get_presence_sensor(RIGHT_CENTER_SENSOR); 
    uint16_t rc3 = get_presence_sensor(RIGHT_CENTER_SENSOR); 
    uint16_t right_center_sensor = (rc1+rc2+rc3)/3;

    uint16_t r1 = get_presence_sensor(RIGHT_SENSOR); 
    uint16_t r2 = get_presence_sensor(RIGHT_SENSOR); 
    uint16_t r3 = get_presence_sensor(RIGHT_SENSOR); 
    uint16_t right_sensor = (r1+r2+r3)/3;

    /*
    uint16_t left_line_sensor = analogRead(LEFT_LINE_SENSOR_PIN);          //sensor de linha
    uint16_t right_line_sensor = analogRead(RIGHT_LINE_SENSOR_PIN);

     if((left_line_sensor<LINE_VALUE) && (right_line_sensor<LINE_VALUE)){
        set_state(BACK_LINE);
        set_is_running(false);
        return;
    }
    else if(left_line_sensor<LINE_VALUE){
        set_state(LEFT_LINE);
        set_is_running(false);
        return;
    }
    else if(right_line_sensor<LINE_VALUE){
        set_state(RIGHT_LINE);
        set_is_running(false);
        return;
    }
    
    Serial.print("esq: ");
    Serial.print(left_center_sensor);
    Serial.print("    |    dir: ");
    Serial.println(right_center_sensor);
    */
    if(left_center_sensor > frente_esq && last_left_center_sensor > frente_esq && right_center_sensor > frente_dir && last_right_center_sensor > frente_dir){
        set_state(ATTACK);
        set_is_running(false);
    }
    else if(left_center_sensor < 10 && right_center_sensor < 50){
        set_state(PERTINHO);
        set_is_running(false);
    }
    else if (left_center_sensor > centro && last_left_center_sensor > centro && right_center_sensor > centro && last_right_center_sensor > centro){
        set_state(CENTER_FOLLOW);
        set_is_running(false);
    }
    else if(right_center_sensor > centro && last_right_center_sensor > centro){
        set_state(RIGHT_CENTER_FOLLOW);
        set_last_seen(RIGHT_SENSOR);
        set_is_running(false);
    }
    else if(left_center_sensor > centro && last_left_center_sensor > centro){
        set_state(LEFT_CENTER_FOLLOW);
        set_last_seen(LEFT_SENSOR);
        set_is_running(false);
    }
    else if(right_sensor > lateral_dir && last_right_sensor > lateral_dir){
        set_state(RIGHT_FOLLOW);
        set_last_seen(RIGHT_SENSOR);
        set_is_running(false);
    }
    else if(left_sensor > lateral_esq && last_left_sensor > lateral_esq){
        set_state(LEFT_FOLLOW);
        set_last_seen(LEFT_SENSOR);
        set_is_running(false);
    }
    else if(get_is_running()){
        set_state(INITIAL_ROUTINE);
    }
    else{    
        set_state(SEARCH);
    }

    last_left_sensor = left_sensor;
    last_left_center_sensor = left_center_sensor;
    last_right_center_sensor = right_center_sensor;
    last_right_sensor = right_sensor;
}

void run_state(){
    switch(current_state){
        case INITIAL_ROUTINE:
            run_initial_routine();
            break;
        case SEARCH:
            if(get_last_seen() == LEFT_SENSOR){
                motor_control(RIGHT, 60);
                motor_control(LEFT, -60);
                Serial.println("Search p esquerda");
            }
            else if(get_last_seen() == RIGHT_SENSOR){
                motor_control(RIGHT, -60);
                motor_control(LEFT, 60);
                Serial.println("Search p direita");
            }
            break;
        case ATTACK:
            motor_control(RIGHT, 255);
            motor_control(LEFT, 255);
            Serial.println("Attack");
            break;
        case PERTINHO:
            Serial.println("pertinho");
            motor_control(RIGHT, 255);
            motor_control(LEFT, 255);
            Serial.println("pertinho");
            break;
        case CENTER_FOLLOW:
            motor_control(RIGHT, 170);
            motor_control(LEFT, 170);
            Serial.println("Center follow");
            break;
        case RIGHT_CENTER_FOLLOW:
            Serial.println("Right center follow");
            motor_control(RIGHT, -127);
            motor_control(LEFT, 200);
            break;
        case LEFT_CENTER_FOLLOW:
            motor_control(LEFT, -127);
            motor_control(RIGHT, 200);
            Serial.println("Left center follow");
            break;
        case RIGHT_FOLLOW:
            Serial.println("Right follow");
            motor_control(RIGHT, -180);
            motor_control(LEFT, 180);
            break;
        case LEFT_FOLLOW:
            motor_control(LEFT, -180);
            motor_control(RIGHT, 180);
            Serial.println("Left follow");
            break;
        case FAILSAFE:
            motor_control(RIGHT, 0);
            motor_control(LEFT, 0);
            Serial.println("Failsafe");
            break;
        default:
            current_state = SEARCH;
            break;
    }

}