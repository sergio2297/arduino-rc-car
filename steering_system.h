#ifndef steering_system_h_
#define steering_system_h_

#include <Arduino.h>
#include <Servo.h>

class SteeringSystem {
	public:
		SteeringSystem(byte pin_servo);
		
		void setup();
		
		int get_current_steering_degrees() const;
		void steering_right(byte degrees);
    void center_steering();
		void steering_left(byte degrees);
		
	private:
		byte steering_degrees;
		
		byte pin_servo;
		Servo servo;
};

#endif
