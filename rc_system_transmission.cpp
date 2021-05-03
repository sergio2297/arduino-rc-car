#include "rc_system_transmission.h"
#include "constants.h"

namespace rc_system {

    RC_System_Transmission::RC_System_Transmission() :
        RC_System(PERIOD_MS_TRANSMISSION_SYSTEM), transmission(PIN_ENABLE_TRANSMISSION_SYSTEM, PIN_FORWARD_TRANSMISSION_SYSTEM, PIN_BACKWARD_TRANSMISSION_SYSTEM) {}
    
    void RC_System_Transmission::setup() {
        transmission.setup();
    }
    
    void RC_System_Transmission::routine(String action) {
        if(action.equals("THROTTLE")) {
            transmission.throttle();
        } else if(action.equals("STOP_THROTTLE")) {
            transmission.stop_throttle();
        } else if(action.equals("BRAKE")) {
            transmission.brake();
        }
    }
}
