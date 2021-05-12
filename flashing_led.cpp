#include "flashing_led.h"

FlashingLed::FlashingLed(byte pin, unsigned long period) 
	: Led(pin), period(period), timestamp(-period) {}

/**
 * is_active is necessary to keep synchronized blinking of differents FlashingLeds with the same period. In this way, their timestamps will keep updated
 */
void FlashingLed::routine(unsigned long current_ms, bool is_active) {
    if(current_ms - timestamp >= period) {
        timestamp += period;
        if(is_active) {
            commutate();   
        }
    }
}
