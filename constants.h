#ifndef constants_h_
#define constants_h_

#include <String.h>

/**
 * Actions that cause some movement or concrete behaviour on the car are UPPER_CASE
 * Actions that make some change on car's configuration are lower_case
 *
 * Also it's common that oppsite actions have the same character with different case type.
 * (UPPER_CASE -> Positive)
 */

//--------------------------------------------------------------------------------
//------------------------------------ System ------------------------------------
#define SYSTEM_END_COMMAND '$'
#define SYSTEM_END_ACTION ';'
#define SYSTEM_NO_ACTION_CODE ' '

// AT+NAME=RaceYourTrack_Car
// AT+PSWD="7806"
// AT+UART=38400,0,0
// AT+ROLE=0  //Slave
#define PIN_RX_BLUETOOTH 12 // Reading
#define PIN_TX_BLUETOOTH 13 // Transmission
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//------------------------------ Transmission System -----------------------------
#define PERIOD_MS_TRANSMISSION_SYSTEM 200
#define PIN_ENABLE_TRANSMISSION_SYSTEM 4
#define PIN_FORWARD_TRANSMISSION_SYSTEM 5   // Need to be a PWM pin
#define PIN_BACKWARD_TRANSMISSION_SYSTEM 6  // Need to be a PWM pin

#define TRANSMISSION_SYSTEM_ACTION_HEADER "T_"
#define TRANSMISSION_SYSTEM_ACTION_THROTTLE 'T'
#define TRANSMISSION_SYSTEM_ACTION_STOP_THROTTLE 'S'
#define TRANSMISSION_SYSTEM_ACTION_BRAKE 'B'
#define TRANSMISSION_SYSTEM_ACTION_SHIFT_UP 'U'
#define TRANSMISSION_SYSTEM_ACTION_SHIFT_DOWN 'D'
// To shift_to action, only is necessary to pass the gear number
#define TRANSMISSION_SYSTEM_ACTION_NEUTRAL 'N'
#define TRANSMISSION_SYSTEM_ACTION_REVERSE 'R'
#define TRANSMISSION_SYSTEM_ACTION_H_SHIFT 'h'
#define TRANSMISSION_SYSTEM_ACTION_SEQUENTIAL_SHIFT 's'
// To config the number of gears it will be neccesary to use ASCII code from characters
//--------------------------------------------------------------------------------


//--------------------------------------------------------------------------------
//--------------------------------- Lights System --------------------------------
#define PERIOD_MS_LIGHTS_SYSTEM 500
#define PERIOD_MS_BLINKING_LIGHTS 750
#define PIN_FRONT_LIGHTS_LIGHTS_SYSTEM 10   // Need to be a PWM pin
#define PIN_BACK_LIGHTS_LIGHTS_SYSTEM 9     // Need to be a PWM pin
#define PIN_REVERSE_LIGHTS_SYSTEM 2
#define PIN_LEFT_BLINKING_LIGHTS_LIGHTS_SYSTEM 7
#define PIN_RIGHT_BLINKING_LIGHTS_LIGHTS_SYSTEM 8

#define LIGHTS_SYSTEM_ACTION_HEADER "L_"
#define LIGHTS_SYSTEM_ACTION_TURN_ON_DIPPED_BEAM_LIGHTS 'D'
#define LIGHTS_SYSTEM_ACTION_TURN_OFF_DIPPED_BEAM_LIGHTS 'd'
#define LIGHTS_SYSTEM_ACTION_TURN_ON_MAIN_BEAM_LIGHTS 'M'
#define LIGHTS_SYSTEM_ACTION_TURN_OFF_MAIN_BEAM_LIGHTS 'm'
#define LIGHTS_SYSTEM_ACTION_TURN_ON_BRAKE_LIGHTS 'B'
#define LIGHTS_SYSTEM_ACTION_TURN_OFF_BRAKE_LIGHTS 'b'
#define LIGHTS_SYSTEM_ACTION_TURN_ON_REVERSE_LIGHTS 'P'
#define LIGHTS_SYSTEM_ACTION_TURN_OFF_REVERSE_LIGHTS 'p'
#define LIGHTS_SYSTEM_ACTION_TURN_ON_LEFT_BLINKING 'L'
#define LIGHTS_SYSTEM_ACTION_TURN_OFF_LEFT_BLINKING 'l'
#define LIGHTS_SYSTEM_ACTION_TURN_ON_RIGHT_BLINKING 'R'
#define LIGHTS_SYSTEM_ACTION_TURN_OFF_RIGHT_BLINKING 'r'
#define LIGHTS_SYSTEM_ACTION_TURN_ON_EMERGENCY_LIGHTS 'E'
#define LIGHTS_SYSTEM_ACTION_TURN_OFF_EMERGENCY_LIGHTS 'e'
//--------------------------------------------------------------------------------


//--------------------------------------------------------------------------------
//------------------------------ Steering System ---------------------------------
#define PERIOD_MS_STEERING_SYSTEM 250
#define PIN_SERVO_STEERING_SYSTEM 3     // Need to be a PWM pin

#define STEERING_SYSTEM_INCREMENT_DEGREES 10
#define STEERING_SYSTEM_ACTION_HEADER "S_"
#define STEERING_SYSTEM_ACTION_RIGHT 'R'
#define STEERING_SYSTEM_ACTION_MIDDLE 'M'
#define STEERING_SYSTEM_ACTION_LEFT 'L'
// To turn the steering a concrete amount of degrees it will be necessary to pass a number (for turn right)
// beteween [0,9] and a letter (for turn left) between [A,J] to use its ASCII code.
//--------------------------------------------------------------------------------


//--------------------------------------------------------------------------------
//------------------------------ RFID System ---------------------------------
#define PERIOD_MS_RFID_SYSTEM 10
#define RFID_SYSTEM_MINIMUM_DELAY_BETWEEN_CHECKS_MS 5000
#define PIN_RFID_SYSTEM_SS 53
#define PIN_RFID_SYSTEM_RESET 49

// Card UID and Key_chain UID are declared in RFID_System.cpp
#define RFID_SYSTEM_CARD_CODE 'C'
#define RFID_SYSTEM_KEY_CHAIN_CODE 'K'
//--------------------------------------------------------------------------------

#endif
