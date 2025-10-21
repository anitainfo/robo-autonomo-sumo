#include <Arduino.h>
#define BATTERY_PIN 2

#define BATTERY_SAMPLE_READINGS     4       // Readings to average
#define BATTERY_VOLTAGE_PARAMETER   12.42   // Voltage calibration parameter
#define BATTERY_ADC_PARAMETER       2555    // ADC calibration parameter

#define BATTERY_LOW_THRESHOLD 11.3          // Low battery voltage
#define BATTERY_HIGH_THRESHOLD 12.4        // High battery voltage
#define USB_THRESHOLD 3.0                   // Below that voltage, we assume USB power

typedef enum{
    BATTERY_HIGH,
    BATTERY_MEDIUM,
    BATTERY_LOW,
    BATTERY_DANGER
}Battery_Status_t;

void battery_setup();
void battery_check();
void battery_monitoring();

Battery_Status_t get_battery_status();
float get_battery_voltage();

