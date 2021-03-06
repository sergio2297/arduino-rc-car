#ifndef transmission_system_h_
#define transmission_system_h_

#include <Arduino.h>

class TransmissionSystem {
	public:
		TransmissionSystem(byte pin_enable, byte pin_forward, byte pin_backward);
		
		void setup() const;

		void set_automatic();
		void set_manual();
		void set_sequential_shift();
		void set_h_shift();

		int get_current_gear() const;
		byte get_number_of_gears() const;
		void set_number_of_gears(byte number_of_gears);

		void engine_routine();

		void shift_up();
		void shift_down();
		void shift_to(int gear);
		void neutral();
		void reverse();
		
		void throttle();
		void stop_throttle();
		void brake();

	private:
		byte calculate_power() const;
		
		bool is_sequential;
		byte current_gear, number_of_gears;
		
		bool is_accelerating;

		byte pin_enable, pin_forward, pin_backward;
};

#endif
