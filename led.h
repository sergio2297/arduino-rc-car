#ifndef led_h_
#define led_h_

#include <Arduino.h>

class Led {
	public:
		Led(byte pin);
		
		void setup() const;
		
		byte get_current_state() const;
		void set_state(byte state);
		void turnOn();
		void turnOff();
        void commutate();
		
	private:
		byte current_state;
		
		byte pin;
	
};

#endif
