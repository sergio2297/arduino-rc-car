#include "steering_system.h"

#define CENTER_POSITION 90
#define MAX_DEGREES 90

/*
 * When you write on a Servo, it needs some delay after the writing. So there are two options for move it properly:
 *  - Increment its posittion one by one without delay after.
 *  - Write directly the tarjet degrees, but it would be necessary to give it some delay for it can reach the tarjet degrees.
 */

SteeringSystem::SteeringSystem(byte pin_servo)
	:  current_steering_degrees(CENTER_POSITION), target_steering_degrees(CENTER_POSITION), increment(0), pin_servo(pin_servo), servo(Servo()) {}
		
void SteeringSystem::setup() {
    servo.attach(pin_servo); //attach() must be call in the sketch's setup void
    center_steering();
}

int SteeringSystem::get_current_steering_degrees() const {
	return current_steering_degrees - CENTER_POSITION;
}

// Function for concurrent behaviour
void SteeringSystem::move_one_degree_to_target() {
    if(current_steering_degrees != target_steering_degrees) {
        current_steering_degrees += increment;
        servo.write(current_steering_degrees);
    }
}

// Function for concurrent behaviour
void SteeringSystem::calculate_current_increment() {
    increment = 0;
    if(((int)current_steering_degrees - target_steering_degrees) < 0) { // go to right
        increment = +1;
    } else if(((int)current_steering_degrees - target_steering_degrees) > 0) { // go to left
        increment = -1;
    }
}

void SteeringSystem::steering_to(byte degrees) {
    int increment = 0;
    if(((int)current_steering_degrees - degrees) < 0) { // go to right
        increment = +1;
    } else if(((int)current_steering_degrees - degrees) > 0) { // go to left
        increment = -1;
    }

    while(current_steering_degrees != degrees) {
        current_steering_degrees += increment;
        servo.write(current_steering_degrees);  
    }
}

void SteeringSystem::steering_right(byte degrees){
	if(degrees > MAX_DEGREES) {
		target_steering_degrees = CENTER_POSITION + MAX_DEGREES;
	} else {
		target_steering_degrees = CENTER_POSITION + degrees;
	}

    calculate_current_increment(); // Concurrent version
    //steering_to(target_steering_degrees); // No concurrent version 
}

void SteeringSystem::steering_right() {
    steering_right(MAX_DEGREES);
}

void SteeringSystem::center_steering() {
    calculate_current_increment(); // Concurrent version
    //steering_to(CENTER_POSITION); // No concurrent version
}

void SteeringSystem::steering_left() {
    steering_left(MAX_DEGREES);
}

void SteeringSystem::steering_left(byte degrees) {
	if(degrees > MAX_DEGREES) {
		target_steering_degrees = CENTER_POSITION - MAX_DEGREES;
	} else {
		target_steering_degrees = CENTER_POSITION - degrees;
	}

    calculate_current_increment();  // Concurrent version
    //steering_to(target_steering_degrees); // No concurrent version
}
