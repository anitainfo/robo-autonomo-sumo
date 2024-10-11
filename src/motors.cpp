#include "Kuroneko.hpp"
#include "motors.hpp"

// void motor_hard_brake(Side side, int16_t* speed_ptr) { -----------------part 2
//     switch (side) {
//         case RIGHT:
//             *speed_ptr = -motor_speed.right / 2;
//             break;
//         case LEFT:
//             *speed_ptr = -motor_speed.left / 2;
//             break;
//         default:
//             break;
//     }
// }

void motor_setup() {
    pinMode(RIGHT_MOTOR_1, OUTPUT);
    pinMode(RIGHT_MOTOR_2, OUTPUT);
    pinMode(LEFT_MOTOR_1, OUTPUT);
    pinMode(LEFT_MOTOR_2, OUTPUT);
}

void motor_control(Side side, int16_t speed) {
    if (speed > MAX_PWR) {
        speed = MAX_PWR;
    }
    else if (speed < -MAX_PWR) {
        speed = -MAX_PWR;
    }

    switch (side) {
    case RIGHT:
        //motor_speed.speed_right = acceleration(motor_speed.speed_right, speed);
        //motor_speed.speed_right = limit_value(motor_speed.speed_right);
        Serial.println(speed);
        if (speed > 0) {
            analogWrite(RIGHT_MOTOR_1, 255-speed);
            analogWrite(RIGHT_MOTOR_2, 255);

        }
        else {
           
            analogWrite(RIGHT_MOTOR_1, 255);
            analogWrite(RIGHT_MOTOR_2, 255+speed);
        }
        break;
    case LEFT:
        //motor_speed.speed_left = acceleration(motor_speed.speed_left, speed);
        //motor_speed.speed_left = limit_value(motor_speed.speed_left);
        Serial.print(speed);
        Serial.print("\t");
        if (speed > 0) {
            analogWrite(LEFT_MOTOR_1, 255-speed);
            analogWrite(LEFT_MOTOR_2, 255);
        }
        else {
            analogWrite(LEFT_MOTOR_1, 255);
            analogWrite(LEFT_MOTOR_2, 255+speed);
        }
    default:
        break;
    }
}
