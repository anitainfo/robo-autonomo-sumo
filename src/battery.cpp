#include <battery.hpp>
#include <led.hpp>

float voltage = 12.00;
Battery_Status_t battery_status = BATTERY_LOW;

void battery_setup(){
    pinMode(BATTERY_PIN, INPUT);
}

uint16_t read_battery_adc(uint8_t number_of_readings) {
    uint64_t avg_battery_readings = 0;
    uint16_t adc_battery_reading = 0;
    // Takes an arithmetic average of ADC values to increase precision
    for (int i = 0; i < number_of_readings; i++) {
        avg_battery_readings += analogRead(BATTERY_PIN);
    }
    avg_battery_readings /= number_of_readings;
    adc_battery_reading = avg_battery_readings;
    return adc_battery_reading;
}

void read_battery_voltage() {
    uint16_t adc_battery_reading = read_battery_adc(BATTERY_SAMPLE_READINGS);
    voltage = ((float)adc_battery_reading * BATTERY_VOLTAGE_PARAMETER) / BATTERY_ADC_PARAMETER; // Based on calibrated values, calculates the battery voltage using rule of linear proportion
    voltage = (round(voltage*10)/10.0);
}

void read_battery_status() {
    if (voltage >= BATTERY_HIGH_THRESHOLD) battery_status = BATTERY_HIGH;
    else if ((voltage < BATTERY_HIGH_THRESHOLD) && (voltage > BATTERY_LOW_THRESHOLD)) battery_status = BATTERY_MEDIUM;
    else if ((voltage <= BATTERY_LOW_THRESHOLD) && (voltage > USB_THRESHOLD)) battery_status = BATTERY_LOW;
    else battery_status = BATTERY_DANGER;
}

void battery_check() {
    battery_monitoring();
    switch (battery_status) {
        case BATTERY_HIGH:
            set_led_color(LED_BAT, GREEN);
            break;
        case BATTERY_MEDIUM:
            set_led_color(LED_BAT, GREEN);
            break;
        case BATTERY_LOW:
            set_led_color(LED_BAT, GREEN);

            break;
        case BATTERY_DANGER:
            set_led_color(LED_BAT, GREEN);
            break;
        default:
            break;
    }
}

void battery_monitoring() {
    read_battery_voltage();
    read_battery_status();
}

Battery_Status_t get_battery_status() {
    return battery_status;
} 

float get_battery_voltage() {
    return voltage;
}