#ifndef rc_system_h_
#define rc_system_h_

#include <Arduino.h>

namespace rc_system {

    class RC_System {
        public:
            // explicit to prevent implicit building
            explicit RC_System(unsigned long period);

            virtual void setup() = 0;
            void loop(String action, unsigned long current_ms);

        protected:
            virtual void routine(String action) = 0;

        private:
            unsigned long period, timestamp;

    };
}

#endif
