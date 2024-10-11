#include "state.hpp"
#include <stdint.h>
#include "motors.hpp"
#include "sensors.hpp"
#include "infrared.hpp"
#include "line_sensor.hpp"
/*
#include <ESP32Servo.h>

Servo servo_motor;  // create servo object to control a servo
// 16 servo objects can be created on the ESP32

// Recommended PWM GPIO pins on the ESP32 include 2,4,12-19,21-23,25-27,32-33 
// Possible PWM GPIO pins on the ESP32-S2: 0(used by on-board button),1-17,18(used by on-board LED),19-21,26,33-42
// Possible PWM GPIO pins on the ESP32-S3: 0(used by on-board button),1-21,35-45,47,48(used by on-board LED)
// Possible PWM GPIO pins on the ESP32-C3: 0(used by on-board button),1-7,8(used by on-board LED),9-10,18-21
#if defined(CONFIG_IDF_TARGET_ESP32S2) || defined(CONFIG_IDF_TARGET_ESP32S3)
int servoPin = 4;
#elif defined(CONFIG_IDF_TARGET_ESP32C3)
int servoPin = 4;
#else
int servoPin = 4;
#endif
*/

static KuronekoStrategyState current_state;

static KuronekoStartingMove starting_routine = NONE;

//bool lado_bandeira = false; // começa fechando a bandeira

//bool girar_bandeira = false; 

void set_state(KuronekoStrategyState new_state) {
    current_state = new_state;
}

KuronekoStrategyState get_state() {
    return current_state;
}

KuronekoStartingMove get_starting_routine(){
    return starting_routine;
}

void set_starting_routine(KuronekoStartingMove move){
    starting_routine = move;
}

/*
void set_bandeira_open(bool open){
    girar_bandeira = open;
}

void set_bandeira_side(bool side){
    lado_bandeira = side;
}
*/

void run_starting_routine() { // com delay
    check_for_failsafe_signal();
    /*
    if(girar_bandeira){ // girar bandeira

        // Allow allocation of all timers
        ESP32PWM::allocateTimer(0);
        ESP32PWM::allocateTimer(1);
        ESP32PWM::allocateTimer(2);
        ESP32PWM::allocateTimer(3);
        servo_motor.setPeriodHertz(50);    // standard 50 hz servo
        servo_motor.attach(servoPin, 500, 2400); // attaches the servo on pin 18 to the servo object
        // using default min/max of 1000us and 2000us
        // different servos may require different min/max settings
        // for an accurate 0 to 180 sweep

        Serial.println("VOU MEXER SERVOOOOOOOOOOOOOOOOOOOOO\n");
        if(lado_bandeira){ // abre p/ direita
            servo_motor.write(180); 
            delay(500);
            Serial.println("mexendo servo\n"); 
        } else{ // fecha bandeira
            servo_motor.write(90); 
            delay(500);
            Serial.println("mexendo servo\n");
        }
        girar_bandeira = false;
    }
    */
    switch (starting_routine) {
        case CHARGE:
            motor_control(RIGHT, MAX_PWR);
            motor_control(LEFT, MAX_PWR);
            delay(280);
            motor_control(RIGHT, -MAX_PWR);
            motor_control(LEFT, -MAX_PWR);
            delay(15);
            break;
        case CHARGE_LEFT:                           //comentarios errados
            motor_control(RIGHT,  MAX_PWR);         // curva esquerda
            motor_control(LEFT,   MAX_PWR);
            delay(200);
            motor_control(RIGHT,  -0.2 * MAX_PWR);  // para
            motor_control(LEFT,  -0.2 * MAX_PWR);
            delay(20);
            motor_control(RIGHT, -MAX_PWR);         // gira direita
            motor_control(LEFT,   MAX_PWR);
            delay(110);
            motor_control(RIGHT,  -0.2 * MAX_PWR);  // para
            motor_control(LEFT,  -0.2 * MAX_PWR);
            delay(30);
            motor_control(RIGHT,  MAX_PWR);         // frente
            motor_control(LEFT,  MAX_PWR);
            delay(160);
            motor_control(RIGHT,  -0.2 * MAX_PWR);  // para
            motor_control(LEFT,  -0.2 * MAX_PWR);
            delay(30);
            motor_control(RIGHT, -MAX_PWR);         // gira direita
            motor_control(LEFT,   MAX_PWR);
            delay(150);
            motor_control(RIGHT,  MAX_PWR);         // frente
            motor_control(LEFT,  MAX_PWR);
            delay(20);
            break;
            break;
        case CHARGE_RIGHT:
            motor_control(RIGHT,  MAX_PWR);         // curva esquerda
            motor_control(LEFT,   MAX_PWR);
            delay(200);
            motor_control(RIGHT,  -0.2 * MAX_PWR);  // para
            motor_control(LEFT,  -0.2 * MAX_PWR);
            delay(20);
            motor_control(RIGHT,  MAX_PWR);         // gira direita
            motor_control(LEFT,  -MAX_PWR);
            delay(130);
            motor_control(RIGHT,  -0.2 * MAX_PWR);  // para
            motor_control(LEFT,  -0.2 * MAX_PWR);
            delay(30);
            motor_control(RIGHT,  MAX_PWR);         // frente
            motor_control(LEFT,  MAX_PWR);
            delay(160);
            motor_control(RIGHT,  -0.2 * MAX_PWR);  // para
            motor_control(LEFT,  -0.2 * MAX_PWR);
            delay(30);
            motor_control(RIGHT,  MAX_PWR);         // gira direita
            motor_control(LEFT,  -MAX_PWR);
            delay(180);
            motor_control(RIGHT,  MAX_PWR);         // frente
            motor_control(LEFT,  MAX_PWR);
            delay(100);
            break;
        case DRAW:
            motor_control(RIGHT, MAX_PWR);
            motor_control(LEFT, -MAX_PWR);
            delay(140);
            motor_control(RIGHT, -0.2 * MAX_PWR);
            motor_control(LEFT,  -0.2 * MAX_PWR);
            delay(20);
            motor_control(RIGHT, MAX_PWR);
            motor_control(LEFT,  MAX_PWR);
            delay(70);
            break;
        case RIGHT_FRONT_DRIBBLE:                       //work in progress
            motor_control(RIGHT,  0.8 * MAX_PWR);
            motor_control(LEFT,  -0.8 * MAX_PWR);
            delay(30);
            motor_control(RIGHT, -0.2 * MAX_PWR);
            motor_control(LEFT,  -0.2 * MAX_PWR);
            delay(20);
            motor_control(RIGHT, MAX_PWR);
            motor_control(LEFT,  MAX_PWR);
            delay(180);
            break;
        case LEFT_FRONT_DRIBBLE:                       //work in progress
            motor_control(RIGHT, -0.8 * MAX_PWR);
            motor_control(LEFT,   0.8 * MAX_PWR);
            delay(30);
            motor_control(RIGHT, -0.2 * MAX_PWR);
            motor_control(LEFT,  -0.2 * MAX_PWR);
            delay(20);
            motor_control(RIGHT, MAX_PWR);
            motor_control(LEFT,  MAX_PWR);
            delay(180);
            break;
        default:
            return;
            break;
    }
}

void update_robot_state() {
    if (get_state() == FAILSAFE_HALT) return;

    // uint16_t line_sensor_left = get_line_sensor_reading(LEFT_SENSOR_STATE);
    // uint16_t line_sensor_right = get_line_sensor_reading(RIGHT_SENSOR_STATE);

    // if(line_sensor_left && line_sensor_right){
    //     set_state(BACK_LINE_MANEUVER);
    //     return;
    // }


    // if(analogRead(LEFT_LINE_SENSOR) < 1000){
    //     set_state(LEFT_LINE_MANEUVER);
    //     return;
    // }
    
    
    // if(line_sensor_right){
    //     set_state(RIGHT_LINE_MANEUVER);
    //     return;
    // }

    uint16_t left_sensor = get_sensor_reading(LEFT_SENSOR);
    uint16_t left_center_sensor = get_sensor_reading(LEFT_CENTER_SENSOR);
    uint16_t right_center_sensor = get_sensor_reading(RIGHT_CENTER_SENSOR);
    uint16_t right_sensor = get_sensor_reading(RIGHT_SENSOR);

    // TODO: adicionar lógica dos QRES em cima
    if (left_center_sensor < 2300 && left_center_sensor > 400 && right_center_sensor < 2300 && right_center_sensor > 400) { // perto e no centro
        set_state(CENTER_SENSOR_TRIGGERED);
    }
    else if (left_center_sensor < 2300  && left_center_sensor > 400 && right_center_sensor > 2300) { // robô adv mais p/ esq
        set_state(LEFT_CENTER_SENSOR_TRIGGERED);
    }
    else if (right_center_sensor < 2300 && right_center_sensor > 400 && left_center_sensor > 2300) { // robô adv mais p/ dir
        set_state(RIGHT_CENTER_SENSOR_TRIGGERED);
    }
    else if (right_sensor < 2300 && right_sensor > 400){ // robô adv na lateral direita
        set_state(RIGHT_SENSOR_TRIGGERED);
    }
    else if (left_sensor < 2300 && left_sensor > 400){ // robô adv na lateral esquerda
        set_state(LEFT_SENSOR_TRIGGERED);
    }
    else {
        set_state(SEARCH);
    }
}

void run_state() {
    switch (current_state) {
    case CENTER_SENSOR_TRIGGERED:
        motor_control(LEFT,  MAX_PWR);
        motor_control(RIGHT, MAX_PWR);
        Serial.println("attack");
        break;
    case LEFT_CENTER_SENSOR_TRIGGERED:
        motor_control(LEFT,  -0.10 * MAX_PWR);
        motor_control(RIGHT, 0.45 * MAX_PWR);
        set_last_seen(LEFT_CENTER_SENSOR);
        Serial.println("left_center");
        break;
    case RIGHT_CENTER_SENSOR_TRIGGERED:
        motor_control(LEFT,   0.45 * MAX_PWR);
        motor_control(RIGHT, -0.10 * MAX_PWR);
        set_last_seen(RIGHT_CENTER_SENSOR);
        Serial.println("right_center");
        break;
    case LEFT_SENSOR_TRIGGERED:
        motor_control(LEFT,  -0.10 * MAX_PWR);
        motor_control(RIGHT, 0.45 * MAX_PWR);
        set_last_seen(LEFT_SENSOR);
        Serial.println("left");
        break;
    case RIGHT_SENSOR_TRIGGERED:
        motor_control(LEFT,   0.45 * MAX_PWR);
        motor_control(RIGHT, -0.10 * MAX_PWR);
        set_last_seen(RIGHT_SENSOR);
        Serial.println("right");
        break;
    case SEARCH:
        if(get_last_seen() == LEFT_SENSOR) {
            motor_control(LEFT,  -0.45 * MAX_PWR);
            motor_control(RIGHT,  0.45 * MAX_PWR);
            Serial.println("search esquerda");
        } else {
            motor_control(LEFT,   0.45 * MAX_PWR);
            motor_control(RIGHT, -0.45 * MAX_PWR);
            Serial.println("search direita");
        }
        break;
    case FAILSAFE_HALT:
        motor_control(LEFT, 0);
        motor_control(RIGHT, 0);
        Serial.println("parar");
        break;
    case BACK_LINE_MANEUVER:
        motor_control(RIGHT, -0.6 * MAX_PWR);
        motor_control(LEFT,  -0.6 * MAX_PWR);
        delay(100);
        motor_control(RIGHT, 0.6 * MAX_PWR);
        motor_control(LEFT, -0.6 * MAX_PWR);
        delay(200);
        motor_control(RIGHT, 0.4 * MAX_PWR);
        motor_control(LEFT,  0.4 * MAX_PWR);
        delay(70);
        break;
    case RIGHT_LINE_MANEUVER:
        motor_control(RIGHT, -0.6 * MAX_PWR);
        motor_control(LEFT,  -0.6 * MAX_PWR);
        delay(100);
        motor_control(RIGHT, 0.6 * MAX_PWR);
        motor_control(LEFT, -0.6 * MAX_PWR);
        delay(100);
        motor_control(RIGHT, 0.4 * MAX_PWR);
        motor_control(LEFT,  0.4 * MAX_PWR);
        delay(70);
        break;
    case LEFT_LINE_MANEUVER:
        // Serial.println("linha esquerda");
        motor_control(RIGHT, -MAX_PWR);
        motor_control(LEFT,  - MAX_PWR);
        delay(200);
        motor_control(RIGHT,  0.6 * MAX_PWR);
        motor_control(LEFT,  -0.6 * MAX_PWR);
        delay(200);
        motor_control(RIGHT,  0.5 * MAX_PWR);
        motor_control(LEFT,   0.5 * MAX_PWR);
        delay(70);
        break;
    default:
        current_state = SEARCH;
        break;
    }
}
