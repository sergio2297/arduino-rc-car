#ifndef rc_system_h_
#define rc_system_h_

#include <cppQueue.h>

/*
 * TODO: Add a virtual function concurrent_action that offer the class some possibilities to do something despite 
 * its period it's not active
 */

namespace rc_system {

    class RC_System {
        public:
            // explicit to prevent implicit building
            explicit RC_System(unsigned long period);

            virtual void setup() = 0;
            void loop(char action, unsigned long current_ms);

        protected:
            virtual void out_of_period_actions(unsigned long current_ms) = 0;
            virtual void routine(char action) = 0;

        private:
            unsigned long period, timestamp;

            cppQueue queue_actions;

    };
}

#endif
