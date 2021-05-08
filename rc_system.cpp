#include "rc_system.h"
#include "constants.h"

namespace rc_system {

    RC_System::RC_System(unsigned long period) :
        period(period), timestamp(-period), queue_actions(sizeof(char), 10, FIFO) {}

    void RC_System::loop(char action, unsigned long current_ms) {
        if(action != SYSTEM_NO_ACTION_CODE) {
           queue_actions.push(&action);
        }
        
        if(current_ms - timestamp >= period) {
            timestamp += period;

            //TODO: Comenzamos el ciclo de trabajo
            if(!queue_actions.isEmpty()) {
                queue_actions.pop(&action);
                routine(action);              
            }
        }
    }

}
