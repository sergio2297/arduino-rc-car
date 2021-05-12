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
        void steering_right();
        void center_steering();
        void steering_left();
		void steering_left(byte degrees);

        void move_one_degree_to_target();
        
	private:
        void steering_to(byte degrees);
        void calculate_current_increment();
    
		byte current_steering_degrees, target_steering_degrees;
        int increment;
		
		byte pin_servo;
		Servo servo;
};

#endif
