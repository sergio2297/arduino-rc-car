#include "lights_system.h"

#define DIPPED_BEAM_LIGHTS_INTENSITY 40
#define MAIN_BEAM_LIGHTS_INTENSITY 255

LightsSystem::LightsSystem(byte pin_front_lights, byte pin_back_lights, byte pin_left_blinking_lights, byte pin_right_blinking_lights)
	: led_front_lights(pin_front_lights), led_back_lights(pin_back_lights), led_left_blinking_lights(pin_left_blinking_lights), led_right_blinking_lights(pin_right_blinking_lights), 
	are_dipped_beam_on(false), are_main_beam_on(false), are_brake_lights_on(false) {}
	
void LightsSystem::setup() const {
	led_front_lights.setup();
	led_back_lights.setup();
	led_left_blinking_lights.setup();
	led_right_blinking_lights.setup();
}

void LightsSystem::turn_dipped_beam_lights(bool state) {
	if(state == true) {
		led_front_lights.set_state(DIPPED_BEAM_LIGHTS_INTENSITY);
        if(!are_brake_lights_on) {
            led_back_lights.set_state(DIPPED_BEAM_LIGHTS_INTENSITY);
        }

		are_dipped_beam_on = true;
	} else {
		led_front_lights.turnOff();
        if(!are_brake_lights_on) {
		    led_back_lights.turnOff();
        }
		are_dipped_beam_on = false;
	}
   
    are_main_beam_on = false;
}

void LightsSystem::turn_main_beam_lights(bool state) {
	if(state == true) {
		led_front_lights.set_state(MAIN_BEAM_LIGHTS_INTENSITY);
        if(!are_brake_lights_on) {
            led_back_lights.set_state(DIPPED_BEAM_LIGHTS_INTENSITY);
        }

        are_main_beam_on = true;
	} else {
	    if(are_dipped_beam_on) {
            led_front_lights.set_state(DIPPED_BEAM_LIGHTS_INTENSITY);
            if(!are_brake_lights_on) {
                led_back_lights.set_state(DIPPED_BEAM_LIGHTS_INTENSITY);
            }
    	} else {
    		led_front_lights.turnOff();
            if(!are_brake_lights_on) {
                led_back_lights.turnOff();
            }
    	}
       
        are_main_beam_on = false;
	}
}

void LightsSystem::turn_brake_lights(bool state) {
	if(state == true) {
		led_back_lights.turnOn();
        are_brake_lights_on = true;
	} else {
	    if(are_dipped_beam_on || are_main_beam_on) {
    		led_back_lights.set_state(DIPPED_BEAM_LIGHTS_INTENSITY);
    	} else {
    		led_back_lights.turnOff();
    	}
        are_brake_lights_on = false;
	}
}

void LightsSystem::turn_left_blinking_lights(bool state) {
    if(state == true) {
        led_left_blinking_lights.turnOn();
    } else {
        led_left_blinking_lights.turnOff();
    }
}

void LightsSystem::turn_right_blinking_lights(bool state) {
    if(state == true) {
        led_right_blinking_lights.turnOn();
    } else {
        led_right_blinking_lights.turnOff();
    }
}

void LightsSystem::turn_emergency_lights(bool state) {
    turn_left_blinking_lights(state);
    turn_right_blinking_lights(state);
}
