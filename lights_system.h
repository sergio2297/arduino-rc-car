#ifndef lights_system_h_
#define lights_system_h_

#include "led.h"

class LightsSystem {
	public:
		LightsSystem(byte pin_front_lights, byte pin_back_lights, byte pin_left_blinking_lights, byte pin_right_blinking_lights);
		
		void setup() const;
		
		void turn_dipped_beam_lights(bool state);
		void turn_main_beam_lights(bool state);
		void turn_brake_lights(bool state);
        void turn_left_blinking_lights(bool state);
        void turn_right_blinking_lights(bool state);
        void turn_emergency_lights(bool state);
        
	private:
		Led led_front_lights;
		Led led_back_lights;
		Led led_left_blinking_lights, led_right_blinking_lights;
	
		bool are_dipped_beam_on, are_main_beam_on, are_brake_lights_on;
        bool are_left_blinking_lights_on, are_right_blinking_lights_on, are_emergency_lights_on;
		
};

#endif
