#include "rc_system_transmission.h"
#include "constants.h"

#define ASCII_CODE_a 97
#define MINIMUM_NUMBER_OF_GEARS 3

namespace rc_system {

    RC_System_Transmission::RC_System_Transmission() :
        RC_System(PERIOD_MS_TRANSMISSION_SYSTEM), transmission(PIN_ENABLE_TRANSMISSION_SYSTEM, PIN_FORWARD_TRANSMISSION_SYSTEM, PIN_BACKWARD_TRANSMISSION_SYSTEM) {}
    
    void RC_System_Transmission::setup() {
        transmission.setup();
    }

    void RC_System_Transmission::routine(char action) {
        switch(action) {
            case TRANSMISSION_SYSTEM_ACTION_THROTTLE:
                transmission.throttle();
                break;

            case TRANSMISSION_SYSTEM_ACTION_STOP_THROTTLE:
                transmission.stop_throttle();
                break;

            case TRANSMISSION_SYSTEM_ACTION_BRAKE:
                transmission.brake();
                break;

            case TRANSMISSION_SYSTEM_ACTION_SHIFT_UP:
                transmission.shift_up();
                break;

            case TRANSMISSION_SYSTEM_ACTION_SHIFT_DOWN:
                transmission.shift_down();
                break;

            case '0':
            case TRANSMISSION_SYSTEM_ACTION_NEUTRAL:
                transmission.neutral();
                break;

            case TRANSMISSION_SYSTEM_ACTION_REVERSE:
                transmission.reverse();
                break;

            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                transmission.shift_to(String(action).toInt());
                break;

            case TRANSMISSION_SYSTEM_ACTION_SECUENCIAL_SHIFT:
                transmission.set_secuencial_shift();
                break;

            case TRANSMISSION_SYSTEM_ACTION_H_SHIFT:
                transmission.set_h_shift();
                break;

            case 'a': //3 gears
            case 'b': //4 gears
            case 'c': //5 gears
            case 'd': //6 gears
            case 'e': //7 gears
            case 'f': //8 gears
            case 'g': //9 gears
                byte gears = ((byte)action) - ASCII_CODE_a;
                transmission.set_number_of_gears(gears + MINIMUM_NUMBER_OF_GEARS);
                break;
            
            default:
                break;
        }
    }
}
