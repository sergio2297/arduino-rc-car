#include "rc_system_lights.h"
#include "constants.h"

namespace rc_system {
	
	RC_System_Lights::RC_System_Lights() :
		RC_System(PERIOD_MS_LIGHTS_SYSTEM), lights(PIN_FRONT_LIGHTS_LIGHTS_SYSTEM, PIN_BACK_LIGHTS_LIGHTS_SYSTEM, PIN_REVERSE_LIGHTS_SYSTEM, PIN_LEFT_BLINKING_LIGHTS_LIGHTS_SYSTEM, PIN_RIGHT_BLINKING_LIGHTS_LIGHTS_SYSTEM, PERIOD_MS_BLINKING_LIGHTS) {}

	void RC_System_Lights::setup() {
		lights.setup();
	}

    void RC_System_Lights::out_of_period_actions(unsigned long current_ms) {
        lights.blinking_lights_routine(current_ms);
    }
    
	void RC_System_Lights::routine(char action) {
		switch(action) {
            case LIGHTS_SYSTEM_ACTION_TURN_ON_DIPPED_BEAM_LIGHTS:
                lights.turn_dipped_beam_lights(true);
                break;

            case LIGHTS_SYSTEM_ACTION_TURN_OFF_DIPPED_BEAM_LIGHTS:
                lights.turn_dipped_beam_lights(false);
                break;

            case LIGHTS_SYSTEM_ACTION_TURN_ON_MAIN_BEAM_LIGHTS:
                lights.turn_main_beam_lights(true);
                break;

            case LIGHTS_SYSTEM_ACTION_TURN_OFF_MAIN_BEAM_LIGHTS:
                lights.turn_main_beam_lights(false);
                break;

            case LIGHTS_SYSTEM_ACTION_TURN_ON_BRAKE_LIGHTS:
                lights.turn_brake_lights(true);
                break;

            case LIGHTS_SYSTEM_ACTION_TURN_OFF_BRAKE_LIGHTS:
                lights.turn_brake_lights(false);
                break;

            case LIGHTS_SYSTEM_ACTION_TURN_ON_REVERSE_LIGHTS:
                lights.turn_reverse_lights(true);
                break;

            case LIGHTS_SYSTEM_ACTION_TURN_OFF_REVERSE_LIGHTS:
                lights.turn_reverse_lights(false);
                break;

            case LIGHTS_SYSTEM_ACTION_TURN_ON_LEFT_BLINKING:
                lights.turn_left_blinking_lights(true);
                break;

            case LIGHTS_SYSTEM_ACTION_TURN_OFF_LEFT_BLINKING:
                lights.turn_left_blinking_lights(false);
                break;

            case LIGHTS_SYSTEM_ACTION_TURN_ON_RIGHT_BLINKING:
                lights.turn_right_blinking_lights(true);
                break;

            case LIGHTS_SYSTEM_ACTION_TURN_OFF_RIGHT_BLINKING:
                lights.turn_right_blinking_lights(false);
                break;

            case LIGHTS_SYSTEM_ACTION_TURN_ON_EMERGENCY_LIGHTS:
                lights.turn_emergency_lights(true);
                break;

            case LIGHTS_SYSTEM_ACTION_TURN_OFF_EMERGENCY_LIGHTS:
                lights.turn_emergency_lights(false);
                break;

            default:
                break;
		}
		
	}
	
}
