#ifndef flashing_led_h_
#define flashing_led_h_

#include <Arduino.h>
#include "led.h"

class FlashingLed : public Led {
	public:
		FlashingLed(byte pin, unsigned long period);
		
		void routine(unsigned long current_ms, bool is_active);
		
	private:
		unsigned long period, timestamp;
	
};

#endif
