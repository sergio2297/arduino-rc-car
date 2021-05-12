#include "rc_system.h"
#include "constants.h"

namespace rc_system {

    RC_System::RC_System(unsigned long period) :
        period(period), timestamp(-period), queue_actions(sizeof(char), 10, FIFO) {}

    void RC_System::loop(char action, unsigned long current_ms) {
        if(action != SYSTEM_NO_ACTION_CODE) {
           queue_actions.push(&action);
        }

        out_of_period_actions(current_ms); // This function is supposed to perform very simple operations
        
        if(current_ms - timestamp >= period) {
            timestamp += period;

            if(!queue_actions.isEmpty()) {
                queue_actions.pop(&action);
                routine(action);              
            }
        }
    }

}
