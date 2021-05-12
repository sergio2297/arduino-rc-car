#ifndef rc_system_steering_h_
#define rc_system_steering_h_

#include "rc_system.h"
#include "steering_system.h"

/*
 * TODO: Make steering_to a concurrent_action where every cycle it's increment is one. Need rc_system refactor
 */

namespace rc_system {

    class RC_System_Steering : public RC_System {
        public:
            RC_System_Steering();
            void setup();
            
        protected:
            void out_of_period_actions(unsigned long current_ms);
            void routine(char action);

        private:
            SteeringSystem steering;

    };
}

#endif
