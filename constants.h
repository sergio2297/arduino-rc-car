#ifndef constants_h_
#define constants_h_

#include <String.h>

/**
 * Actions that cause some movement or concrete behaviour on the car are UPPER_CASE
 * Actions that make some change on car's configuration are lower_case
 */

//--------------------------------------------------------------------------------
//------------------------------------ System ------------------------------------
#define SYSTEM_END_COMMAND '$'
#define SYSTEM_END_ACTION ';'
#define SYSTEM_NO_ACTION_CODE ' '
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
//------------------------------ Transmission System -----------------------------
#define PERIOD_MS_TRANSMISSION_SYSTEM 200
#define PIN_ENABLE_TRANSMISSION_SYSTEM 2
#define PIN_FORWARD_TRANSMISSION_SYSTEM 5
#define PIN_BACKWARD_TRANSMISSION_SYSTEM 6

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
#define TRANSMISSION_SYSTEM_ACTION_SECUENCIAL_SHIFT 's'
// To config the number of gears it will neccesary to use ASCII code from characters
//--------------------------------------------------------------------------------


//--------------------------------------------------------------------------------
//------------------------------ Steering System ---------------------------------
#define PERIOD_MS_STEERING_SYSTEM 350
#define PIN_SERVO_STEERING_SYSTEM 9

#define STEERING_SYSTEM_ACTION_HEADER "S_"
#define STEERING_SYSTEM_ACTION_RIGHT 'R'
#define STEERING_SYSTEM_ACTION_MIDDLE 'M'
#define STEERING_SYSTEM_ACTION_LEFT 'L'
//--------------------------------------------------------------------------------

#endif
