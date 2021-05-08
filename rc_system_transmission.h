#ifndef rc_system_transmission_h_
#define rc_system_transmission_h_

#include "rc_system.h"
#include "transmission_system.h"

/*
 * TODO: make actions like throttle concurrent and work with "work cycles". Need rc_system refactor
 */

namespace rc_system {

    class RC_System_Transmission : public RC_System {
        public:
            RC_System_Transmission();
            void setup();

        protected:
            void routine(char action);

        private:
            TransmissionSystem transmission;

    };
}

#endif
