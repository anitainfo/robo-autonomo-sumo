#include <motors.hpp>

void motor_setup() {
   pinMode(RIGHT_MOTOR_1, OUTPUT);
   pinMode(LEFT_MOTOR_1, OUTPUT);
   pinMode(RIGHT_MOTOR_2, OUTPUT);
   pinMode(LEFT_MOTOR_2, OUTPUT);
}

void motor_control(Side_t side, int16_t speed) {
    if (speed>255){
        speed=255;
    }
    else if(speed <-255){
        speed=-255;
    }

    switch (side) {
        case RIGHT:
           if (speed > 0) {
               analogWrite(RIGHT_MOTOR_1, 255-speed);
               analogWrite(RIGHT_MOTOR_2, 255);
           }else {
               analogWrite(RIGHT_MOTOR_1, 255);
               analogWrite(RIGHT_MOTOR_2, 255+speed);
           }                    
           break;
      
        case LEFT:
           if (speed > 0) {
               
               analogWrite(LEFT_MOTOR_1, 255-speed);
               analogWrite(LEFT_MOTOR_2, 255);
           }else {
               analogWrite(LEFT_MOTOR_1, 255);
               analogWrite(LEFT_MOTOR_2, 255+speed);
           }
           break;
      
        default:
           break;
    }
}
