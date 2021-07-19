#include <Arduino.h>
#include <SoftwareSerial.h>
#include "String.h"
#include "constants.h"
#include "rc_system_transmission.h"
#include "rc_system_lights.h"
#include "rc_system_steering.h"

using namespace rc_system;

#define NUM_SYSTEMS 3
#define TRANSMISSION_SYSTEM_ID 0
#define LIGHTS_SYSTEM_ID 1
#define STEERING_SYSTEM_ID 2

SoftwareSerial bluetooth(PIN_RX_BLUETOOTH, PIN_TX_BLUETOOTH);
RC_System_Transmission transmission;
RC_System_Lights lights;
RC_System_Steering steering;

void readActionsFromSerial(char actions[]) {
    for(int i = 0; i < NUM_SYSTEMS; ++i) {
        actions[i] = SYSTEM_NO_ACTION_CODE;
    }
  
    if(Serial.available() > 0) {
        String command_input = Serial.readStringUntil(SYSTEM_END_COMMAND);
        
        int last_indexOf_separator = 0;
        int indexOf_separator = command_input.indexOf(SYSTEM_END_ACTION);
        while(indexOf_separator != -1) {
            String splitted_command = command_input.substring(last_indexOf_separator, indexOf_separator);

            if(splitted_command.startsWith(TRANSMISSION_SYSTEM_ACTION_HEADER)) {
                splitted_command.replace(TRANSMISSION_SYSTEM_ACTION_HEADER, "");
                actions[TRANSMISSION_SYSTEM_ID] = splitted_command.charAt(0);
            } else if(splitted_command.startsWith(LIGHTS_SYSTEM_ACTION_HEADER)) {
                splitted_command.replace(LIGHTS_SYSTEM_ACTION_HEADER, "");
                actions[LIGHTS_SYSTEM_ID] = splitted_command.charAt(0);
            } else if(splitted_command.startsWith(STEERING_SYSTEM_ACTION_HEADER)) {
                splitted_command.replace(STEERING_SYSTEM_ACTION_HEADER, "");
                actions[STEERING_SYSTEM_ID] = splitted_command.charAt(0);
            }
            
            last_indexOf_separator = indexOf_separator + 1; // Para saltar el separador
            indexOf_separator = command_input.indexOf(SYSTEM_END_ACTION, last_indexOf_separator);
        }
    }
}

void readActionsFromBluetooth(char actions[]) {
    for(int i = 0; i < NUM_SYSTEMS; ++i) {
        actions[i] = SYSTEM_NO_ACTION_CODE;
    }

    if(bluetooth.available() > 0) {
        String command_input = bluetooth.readStringUntil(SYSTEM_END_COMMAND);
        
        int last_indexOf_separator = 0;
        int indexOf_separator = command_input.indexOf(SYSTEM_END_ACTION);
        while(indexOf_separator != -1) {
            String splitted_command = command_input.substring(last_indexOf_separator, indexOf_separator);

            if(splitted_command.startsWith(TRANSMISSION_SYSTEM_ACTION_HEADER)) {
                splitted_command.replace(TRANSMISSION_SYSTEM_ACTION_HEADER, "");
                actions[TRANSMISSION_SYSTEM_ID] = splitted_command.charAt(0);
            } else if(splitted_command.startsWith(LIGHTS_SYSTEM_ACTION_HEADER)) {
                splitted_command.replace(LIGHTS_SYSTEM_ACTION_HEADER, "");
                actions[LIGHTS_SYSTEM_ID] = splitted_command.charAt(0);
            } else if(splitted_command.startsWith(STEERING_SYSTEM_ACTION_HEADER)) {
                splitted_command.replace(STEERING_SYSTEM_ACTION_HEADER, "");
                actions[STEERING_SYSTEM_ID] = splitted_command.charAt(0);
            }
            
            last_indexOf_separator = indexOf_separator + 1; // Para saltar el separador
            indexOf_separator = command_input.indexOf(SYSTEM_END_ACTION, last_indexOf_separator);
        }
    }
}

void setup() {
    if(Serial) {
      Serial.begin(9600);
    }

    bluetooth.begin(38400);
    transmission.setup();
    lights.setup();
    steering.setup();
}

void loop() {
    unsigned long current_ms = millis();
    char actions[NUM_SYSTEMS];
    // readActionsFromSerial(actions); // Used for debug and test 
    readActionsFromBluetooth(actions);
    
    transmission.loop(actions[TRANSMISSION_SYSTEM_ID], current_ms);
    lights.loop(actions[LIGHTS_SYSTEM_ID], current_ms);
    steering.loop(actions[STEERING_SYSTEM_ID], current_ms);

}
