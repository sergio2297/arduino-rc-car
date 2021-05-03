#include "rc_system_steering.h"
#include "constants.h"

namespace rc_system {

    RC_System_Steering::RC_System_Steering() :
        RC_System(PERIOD_MS_STEERING_SYSTEM), steering(PIN_SERVO_STEERING_SYSTEM) {}

    void RC_System_Steering::setup() {
        steering.setup();
    }
    
    void RC_System_Steering::routine(String action) {
          steering.steering_right(steering.get_current_steering_degrees()+1);
    }
}
