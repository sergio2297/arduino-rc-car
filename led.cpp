#include "led.h"

Led::Led(byte pin) 
	: current_state(0), pin(pin) {}
		
void Led::setup() const {
	pinMode(pin, OUTPUT);
}
		
byte Led::get_current_state() const {
	return current_state;
}

void Led::set_state(byte state) {
	current_state = state;
	analogWrite(pin, current_state);
}

void Led::turnOn() {
	set_state(255);
}

void Led::turnOff() {
	set_state(0);
}

void Led::commutate() {
    if(current_state == 0) {
        turnOn();
    } else {
        turnOff();
    }
}
