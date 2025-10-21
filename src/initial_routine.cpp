
#include "initial_routine.hpp"
#include "state.hpp"
#include "motors.hpp"
#include "infrared.hpp"
#include "presence_sensor.hpp"

// dentro da matriz não usar algo*MAX_PWR para termos valores inteiros (int16_t) por questão de espaço 

const uint8_t charge_steps = 1;
int16_t charge_moves[charge_steps][3] = {
    {255, 255, 200},
}; 

const uint8_t draw_steps = 2;
int16_t draw_moves[draw_steps][3] = {
    {255, -255, 300},
    {255, 255, 200}
}; 

const uint8_t left_halfmoon_steps = 5;
int16_t left_halfmoon_moves[left_halfmoon_steps][3] = {
    {255, 255, 230},
    {255, -255, 150},
    {255, 255, 150},
    {255, -255, 300},
    {255, 255, 100}
};

const uint8_t right_halfmoon_steps = 5;
int16_t right_halfmoon_moves[right_halfmoon_steps][3] = {
    {255, 255, 230},
    {-255, 255, 180},
    {255, 255, 250},
    {-255, 255, 200},
    {255, 255, 100}
}; 

const uint8_t left_charge_steps = 2;
int16_t left_charge_moves[left_charge_steps][3] = {
    {122, -122, 40},
    {255, 255, 200}
};

const uint8_t right_charge_steps = 2;
int16_t right_charge_moves[right_charge_steps][3] = {
    {-122, 122, 40},
    {255, 255, 200}
};

const uint8_t left_dribble_steps = 4;
int16_t left_dribble_moves[left_dribble_steps][3] = {
    {-122, 122, 60},
    {255, 255, 200},
    {255, -225, 180},
    {255, 255, 100}
};

const uint8_t right_dribble_steps = 4;
int16_t right_dribble_moves[right_dribble_steps][3] = {
    {122, -122, 60},
    {255, 255, 200},
    {-225, 225, 200},
    {255, 255, 100}

}; 

const uint8_t none_steps = 1;
int16_t none_moves[none_steps][3] = {
    {0, 0, 0}
}; 

static uint8_t num_steps;
static int16_t (*moves)[3];

void set_initial_routine(Initial_routine_t selected_routine){

    // if(selected_routine == RADIO_CONTROL){
    //     run_remote_control();
    //     return;
    // }        // comentado para liberar espaço 
    
    check_for_failsafe_signal();
    switch(selected_routine){
        case SELECT_LEFT:   
            set_last_seen(LEFT_SENSOR);
            break;
        case SELECT_RIGHT:
            set_last_seen(RIGHT_SENSOR); 
            break;
        case CHARGE:            
            num_steps = charge_steps;
            moves = charge_moves;
            break;
        case DRAW:              // empate
            num_steps = draw_steps;
            moves = draw_moves;
            break;
        case LEFT_HALFMOON:     //meia lua pela esquerda
            num_steps = left_halfmoon_steps;
            moves = left_halfmoon_moves;
            break;
        case RIGHT_HALFMOON:        //meia lua pela direita
            num_steps = right_halfmoon_steps;
            moves = right_halfmoon_moves;
            break;
        case LEFT_CHARGE:       //posicionado para esqueda, vira e dá charge reto
            num_steps = left_charge_steps;
            moves = left_charge_moves;
            break;
        case RIGHT_CHARGE:      // posicionado para direita, vira e dá charge reto
            num_steps = right_charge_steps;
            moves = right_charge_moves;
            break;
        case LEFT_DRIBBLE:      // posicionado reto, vira para a esquerda e faz quarto de lua
            set_last_seen(RIGHT_SENSOR);
            num_steps = left_dribble_steps;
            moves = left_dribble_moves;
            break;
        case RIGHT_DRIBBLE:      // posicionado reto, vira para a direita e faz quarto de lua
            num_steps = right_dribble_steps;
            moves = right_dribble_moves;
            break;
        case NONE:
            num_steps = none_steps;
            moves = none_moves;
        default:
            break;
    }
    Serial.print("Rotina inicial escolhida: ");
    Serial.println(selected_routine);
}

static uint32_t change_move_initial = 0;
static uint8_t step = 0;           
static bool change_move;     
static bool start = true;
static bool is_running = true;

void set_is_running(bool new_is_running){
    is_running = new_is_running;
}

bool get_is_running(){
    return is_running;
}

void run_initial_routine(){
    check_for_failsafe_signal();
    if(start){
        start = false;
        is_running = true;        
        change_move = false;
        change_move_initial = millis() + moves[0][2];
        Serial.println("Começou a rotina inicial");
    }
    if(step == num_steps-1 && millis() > change_move_initial){
        is_running = false;
        Serial.println("Acabou a rotina inicial");
        return;
    }
    if (change_move && step != num_steps - 1) {
        step = step + 1;
        change_move_initial = millis() + moves[step][2];
        Serial.print("Mudou para o passo: ");
        Serial.println(step);
    }
    if (millis() < change_move_initial) {
        change_move = false;
        // Serial.print(moves[step][0]);
        // Serial.print("\t");
        // Serial.println(moves[step][1]);
        motor_control(LEFT, moves[step][0]);
        motor_control(RIGHT, moves[step][1]);
    } else {
        change_move = true;
    }
}