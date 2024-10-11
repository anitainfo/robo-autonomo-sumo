#include "Kuroneko.hpp"
#include "infrared.hpp"
#include "motors.hpp"
#include "state.hpp"
#include "sensors.hpp"
#include "line_sensor.hpp"

void setup() {
    Serial.begin(115200);
    Serial.println("oi\n");
    pinMode(LED_BUILTIN, OUTPUT);
    // setup_line_sensors();
    analogWriteFrequency(50000);
    // print_introduction();
    infrared_setup();
    motor_setup();
    sensors_setup();
    define_starting_routine();
    wait_referee_signal();
    run_starting_routine();
}

void loop() {
    read_sensors();
    print_sensors();
    delay(100);
    check_for_failsafe_signal();
    // read_line_sensors();
    update_robot_state();
    run_state();
}
