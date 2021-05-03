#ifndef rc_system_steering_h_
#define rc_system_steering_h_

#include "rc_system.h"
#include "steering_system.h"
#include <Arduino.h>

namespace rc_system {

    class RC_System_Steering : public RC_System {
        public:
            RC_System_Steering();
            void setup();
            
        protected:
            void routine(String action);

        private:
            SteeringSystem steering;

    };
}

#endif
