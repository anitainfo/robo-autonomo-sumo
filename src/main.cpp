#include "motors.hpp"
#include "infrared.hpp"
#include "presence_sensor.hpp"
#include "state.hpp"
#include "line_sensor.hpp"
#include "initial_routine.hpp"
#include "LED.hpp"

void setup () {
   Serial.begin(9600);
   led_setup();
   set_led_color(LED_ROT, WHITE);
   motor_setup();
   analogWriteFrequency(50000);
   presence_sensor_setup();
   infrared_setup();
   //line_sensors_setup();
   define_initial_routine();
   wait_referee_signal();
}

void loop() {
   set_all_leds_colors(GREEN);
   check_for_failsafe_signal();
   update_presence_sensor();  
   //print_sensors();
   decide_state(); 
   run_state();
}