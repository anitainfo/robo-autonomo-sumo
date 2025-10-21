#include "led.hpp"
#include <FastLED.h>

CRGB leds[NUMBER_OF_LEDS];


void led_setup() {
    FastLED.addLeds<NEOPIXEL, LED_RGB_PIN>(leds, NUMBER_OF_LEDS);
    Serial.println("led ok");
}

void set_led_color(Leds_t led_index, uint8_t red, uint8_t green, uint8_t blue) {
    leds[led_index] = CRGB(red, green, blue);
    FastLED.show();
}

void set_all_leds_colors(uint8_t red, uint8_t green, uint8_t blue) {
    for (uint8_t current_led = 0; current_led < NUMBER_OF_LEDS; current_led++) {
        leds[current_led] = CRGB(red, green, blue);
    }
    FastLED.show();
}

void clear_leds() {
    FastLED.clear(true);
}

