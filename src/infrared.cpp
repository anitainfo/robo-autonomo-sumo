#include "infrared.hpp"
#include <IRremote.hpp>
#include "state.hpp"
#include "sensors.hpp"

void infrared_setup() {
    IrReceiver.begin(IR_SENSOR, false);
}
void wait_referee_signal(void) {
    while (true) {
        if (IrReceiver.decode()) {
            switch (IrReceiver.lastDecodedCommand) {
            case FIGHT_START_BUTTON:
                return;
            default:
                break;
            }
            IrReceiver.printIRResultShort(&Serial);
            IrReceiver.resume();
        }
    }
}

void define_starting_routine(void) {
    IrReceiver.decode();
    while (IrReceiver.lastDecodedCommand != OK_BUTTON) {
        if (IrReceiver.decode()) {
            switch (IrReceiver.lastDecodedCommand) {// da pra combar right e left start com outros movimentos
                case RIGHT_START_BUTTON:                // comeca girando pra direita 
                    // se só esse botão for apertado não haverá movimento inicial, ele vai girar pra direita apenas
                    set_last_seen(RIGHT_SENSOR);
                    break;
                case LEFT_START_BUTTON:                 // comeca girando pra esquerda
                    // se só esse botão for apertado não haverá movimento inicial, ele vai girar pra esquerda apenas
                    set_last_seen(LEFT_SENSOR);
                    break;
                case DRAW_BUTTON:                       // para o desempate, da 180 graus
                    set_starting_routine(DRAW);
                    break;
                case CHARGE_BUTTON:
                    set_starting_routine(CHARGE);      // vai reto
                    break;
                case CHARGE_LEFT_BUTTON:
                    set_starting_routine(CHARGE_LEFT); // vai reto e para a esquerda
                    break;
                case CHARGE_RIGHT_BUTTON:
                    set_starting_routine(CHARGE_RIGHT);// vai reto e para a direita
                    break;
                case RIGHT_FRONT_DRIBBLE_BUTTON:
                    set_starting_routine(RIGHT_FRONT_DRIBBLE);
                    break;
                case LEFT_FRONT_DRIBBLE_BUTTON:
                    set_starting_routine(LEFT_FRONT_DRIBBLE);
                    break;
            }
            IrReceiver.printIRResultShort(&Serial);
            IrReceiver.resume();
        }
    }
}

    void check_for_failsafe_signal(void) { //checa o fail safe
        if (IrReceiver.decode()) {
            if (IrReceiver.lastDecodedCommand == STOP_BUTTON) {
                set_state(FAILSAFE_HALT);
            }
            IrReceiver.printIRResultShort(&Serial);
            IrReceiver.resume();
        }
    }
