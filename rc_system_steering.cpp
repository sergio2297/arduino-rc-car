#include "rc_system_steering.h"
#include "constants.h"

#define ASCII_CODE_A 65;

namespace rc_system {

    RC_System_Steering::RC_System_Steering() :
        RC_System(PERIOD_MS_STEERING_SYSTEM), steering(PIN_SERVO_STEERING_SYSTEM) {}

    void RC_System_Steering::setup() {
        steering.setup();
    }
    
    void RC_System_Steering::routine(char action) {
         switch(action) {
            case STEERING_SYSTEM_ACTION_RIGHT:
                steering.steering_right();
                break;
            
            case STEERING_SYSTEM_ACTION_MIDDLE:
                steering.center_steering();
                break;

            case STEERING_SYSTEM_ACTION_LEFT:
                steering.steering_left();
                break;

            case '0': //0 degrees
            case '1': //10 degrees
            case '2': //20 degrees
            case '3': //30 degrees
            case '4': //40 degrees
            case '5': //50 degrees
            case '6': //60 degrees
            case '7': //70 degrees
            case '8': //80 degrees
            case '9': //90 degrees
                steering.steering_right(String(action).toInt() * 10);
                break;

            case 'A': //0 degrees
            case 'B': //10 degrees
            case 'C': //20 degrees
            case 'D': //30 degrees
            case 'E': //40 degrees
            case 'F': //50 degrees
            case 'G': //60 degrees
            case 'H': //70 degrees
            case 'I': //80 degrees
            case 'J': //90 degrees
                int degrees = ((int)action) - ASCII_CODE_A;
                steering.steering_left(degrees * 10);
                break;
            
            default:
                break;
         }
    }
}
