#include "rc_system_transmission.h"
#include "rc_system_steering.h"
#include <Arduino.h>

using namespace rc_system;

RC_System_Transmission transmission;
RC_System_Steering steering;

void setup() {
    if(Serial) {
      Serial.begin(9600);
    }

    transmission.setup();
    steering.setup();
}

void loop() {
    unsigned long current_ms = millis();
    String action = "";
    
    transmission.loop(action, current_ms);
    steering.loop(action, current_ms);
}
