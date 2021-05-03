#ifndef rc_system_transmission_h_
#define rc_system_transmission_h_

#include "rc_system.h"
#include "transmission_system.h"
#include <Arduino.h>

namespace rc_system {

    class RC_System_Transmission : public RC_System {
        public:
            RC_System_Transmission();

        protected:
            void routine(String action);

        private:
            TransmissionSystem transmission;

    };

}

#endif
