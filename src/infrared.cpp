#include "infrared.hpp"
#include "state.hpp"
#include "motors.hpp"
#include "initial_routine.hpp"
#include "LED.hpp"

#include <IRremote.hpp>
#define DECODE_SONY

void infrared_setup() {
    IrReceiver.begin(INFRARED_PIN, false);
}

void wait_referee_signal() {
   while(true) {
       if(IrReceiver.decode()){
           switch (IrReceiver.lastDecodedCommand)
           {
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

void define_initial_routine() {
    set_initial_routine(NONE);
    IrReceiver.decode();
    while(IrReceiver.lastDecodedCommand != OK_BUTTON){
        if(IrReceiver.decode()) {
            switch (IrReceiver.lastDecodedCommand){
                // case RADIO_CONTROL_BUTTON:
                //     set_initial_routine(RADIO_CONTROL);
                //     break;
                case SELECT_LEFT_BUTTON:
                    set_initial_routine(SELECT_LEFT);
                    break;
                case SELECT_RIGHT_BUTTON:
                    set_initial_routine(SELECT_RIGHT);
                    break;
                case CHARGE_BUTTON:
                    set_initial_routine(CHARGE);
                    break;
                case DRAW_BUTTON:
                    set_initial_routine(DRAW);
                    break;
                case LEFT_HALFMOON_BUTTON:
                    set_initial_routine(LEFT_HALFMOON);
                    break;
                case RIGHT_HALFMOON_BUTTON:
                    set_initial_routine(RIGHT_HALFMOON);
                    break;
                case LEFT_CHARGE_BUTTON:
                    set_initial_routine(LEFT_CHARGE);
                    break;
                case RIGHT_CHARGE_BUTTON:
                    set_initial_routine(RIGHT_CHARGE);
                    break;
                case LEFT_DRIBBLE_BUTTON:
                    set_initial_routine(LEFT_DRIBBLE);
                    break;
                case RIGHT_DRIBBLE_BUTTON:
                    set_initial_routine(RIGHT_DRIBBLE);
                    break;
                default:
                    set_initial_routine(NONE);
                    break;
            }
            IrReceiver.printIRResultShort(&Serial);
            IrReceiver.resume();
        }
   }
   set_all_leds_colors(YELLOW);
}

void check_for_failsafe_signal() {
    if(IrReceiver.decode()) {
        if(IrReceiver.lastDecodedCommand == STOP_BUTTON) {
            set_state(FAILSAFE);
        }
        IrReceiver.printIRResultShort(&Serial);
        IrReceiver.resume();
       }
   }

