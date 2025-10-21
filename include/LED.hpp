#pragma once
#include <FastLED.h>

#define LED_RGB_PIN 8
#define NUMBER_OF_LEDS 2

#define RED             255, 0, 0
#define DARK_ORANGE     254, 23, 0   //draw
#define LIGHT_ORANGE    255, 48, 0
#define YELLOW          255, 115, 0  //ok
#define LIME_GREEN      163, 251, 0
#define GREEN           0, 230,   0  //rodando
#define EMERALD         0, 250, 40
#define CIAN            0, 255, 255
#define LIGHT_BLUE      50, 50, 232  //muito igual o branco - left half moon
#define BLUE            0,   0, 255     //right half moon
#define PURPLE          137,   0, 255 //right dribble
#define LIGHT_PURPLE    150,   75, 255 //left dribble
#define PINK            240,   0, 80 //right charge
#define LIGHT_PINK      255,   50, 150 //left charge
#define SCARLET         152, 0, 0  //charge
#define WHITE           200, 200, 200  //geral

typedef enum{
    LED_ROT = 0,
    LED_BAT,
}Leds_t;

void led_setup();
void set_led_color(Leds_t led_index, uint8_t red, uint8_t green, uint8_t blue);
void set_all_leds_colors(uint8_t red, uint8_t green, uint8_t blue);
void clear_leds();

uint8_t last_color_led();
