#include "rc_system.h"

namespace rc_system {

    RC_System::RC_System(unsigned long period) :
        period(period), timestamp(-period) {}

    void RC_System::loop(String action, unsigned long current_ms) {
        if(current_ms - timestamp >= period) {
            timestamp += period;

            //TODO: Comenzamos el ciclo de trabajo
            routine(action);
        }
    }

}
