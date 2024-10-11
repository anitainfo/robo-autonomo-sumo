/**
 * @file motors.hpp
 * @author Eduardo Schroeder Pereira dos Santos (duschroeder200@gmail.com)
 * @brief Motor
 * @version 0.1
 * @date 2023-03-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once
#include <stdint.h>

#define MAX_PWR 255 // maximum engine power

typedef enum {
    RIGHT = 0,
    LEFT,
} Side;

void motor_control(Side side, int16_t speed);

void motor_setup();

// Fazer arquivo que lida com as responsabilidades dos motores
// - configuração de pinos e inicialização de variáveis
// - mandar pwm pros motores

