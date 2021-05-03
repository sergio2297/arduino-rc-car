#include "steering_system.h"

#define CENTER_POSITION 90
#define MAX_DEGREES 90

SteeringSystem::SteeringSystem(byte pin_servo)
	:  steering_degrees(CENTER_POSITION), pin_servo(pin_servo), servo(Servo()) {}
		
void SteeringSystem::setup() {
	servo.attach(pin_servo); //attach() must be call in the sketch's setup void
  (*this).center_steering();
}

int SteeringSystem::get_current_steering_degrees() const {
	return steering_degrees - CENTER_POSITION;
}

void SteeringSystem::steering_right(byte degrees){
	if(degrees > MAX_DEGREES) {
		steering_degrees = CENTER_POSITION + MAX_DEGREES;
	} else if(degrees < 0) {
		center_steering();
	} else {
		steering_degrees = CENTER_POSITION + degrees;
	}

	servo.write(steering_degrees);
}

void SteeringSystem::center_steering() {
  steering_degrees = CENTER_POSITION;
  servo.write(steering_degrees);
}

void SteeringSystem::steering_left(byte degrees) {
	if(degrees > MAX_DEGREES) {
		steering_degrees = CENTER_POSITION - MAX_DEGREES;
	} else if(degrees < 0) {
		center_steering();
	} else {
		steering_degrees = CENTER_POSITION - degrees;
	}
	
	servo.write(steering_degrees);
}
