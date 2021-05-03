#include "transmission_system.h"

#define NEUTRAL 1
#define REVERSE 0
#define SHORT_GEAR_POWER 255
#define LONG_GEAR_POWER 190
/**
 * current_gear is stored in a byte variable, so it's not possible to put it negative. That's why
 * the expressions related with shifting and gears aren't ituitive. If the highest gear of the car 
 * is number 6, the variable current_gear will reach 7, because REVERSE = 0 and NEUTRAL = 1.
 */ 

TransmissionSystem::TransmissionSystem(byte pin_enable, byte pin_forward, byte pin_backward) 
	: is_automatic(false), is_secuencial(false), current_gear(0), number_of_gears(5), pin_enable(pin_enable), pin_forward(pin_forward), pin_backward(pin_backward) {}

void TransmissionSystem::setup() const {
	pinMode(pin_enable, OUTPUT);
	pinMode(pin_forward, OUTPUT);
	pinMode(pin_backward, OUTPUT);
}

void TransmissionSystem::set_automatic() {
	is_automatic = true;
}

void TransmissionSystem::set_manual() {
	is_automatic = false;
}

void TransmissionSystem::set_secuencial_shift() {
	is_secuencial = true;
}

void TransmissionSystem::set_h_shift() {
	is_secuencial = false;
}

int TransmissionSystem::get_current_gear() const {
	return ((int)current_gear) - 1;
}

byte TransmissionSystem::get_number_of_gears() const {
	return number_of_gears;
}

void TransmissionSystem::set_number_of_gears(byte number_of_gears) {
	(*this).number_of_gears = number_of_gears;
}

void TransmissionSystem::shift_up() {
	current_gear = (current_gear < number_of_gears + 1) ? current_gear + 1 : current_gear;
}

void TransmissionSystem::shift_down() {
	current_gear = current_gear > REVERSE ? current_gear - 1 : current_gear;
}

void TransmissionSystem::shift_to(int gear) {
	if(!is_secuencial && ((REVERSE -1) <= gear && gear <= number_of_gears)) {
		byte gear_to_shift = ((byte)gear + 1);
		current_gear = gear_to_shift;
	}
}

void TransmissionSystem::neutral() {
	current_gear = NEUTRAL;
}

void TransmissionSystem::reverse() {
	current_gear = REVERSE;
}

//TODO: Trabajar con el ciclo de trabajo
byte TransmissionSystem::calculate_power() const {
	if(current_gear == REVERSE) {
		return SHORT_GEAR_POWER; 
	} else if(current_gear == NEUTRAL) {
		return 0;
	} else {
		byte normaliced_current_gear = current_gear - 1; // Normalize the gear
		return normaliced_current_gear <= (number_of_gears/2) ? SHORT_GEAR_POWER : LONG_GEAR_POWER;
	}
}

void TransmissionSystem::throttle() const {
	analogWrite(pin_enable, calculate_power());
	if(current_gear == REVERSE) {
		digitalWrite(pin_forward, LOW);
		digitalWrite(pin_backward, HIGH);
	} else {
		digitalWrite(pin_forward, HIGH);
		digitalWrite(pin_backward, LOW);
	}
}

void TransmissionSystem::stop_throttle() const {
	digitalWrite(pin_enable, LOW);
}

void TransmissionSystem::brake() const {
	digitalWrite(pin_enable, HIGH);
	if(current_gear == REVERSE) {
		digitalWrite(pin_forward, HIGH);
		digitalWrite(pin_backward, LOW);
		delay(100);
		digitalWrite(pin_forward, LOW);
	} else {
		digitalWrite(pin_forward, LOW);
		digitalWrite(pin_backward, HIGH);
		delay(100);
		digitalWrite(pin_backward, LOW);
	}
	
}
