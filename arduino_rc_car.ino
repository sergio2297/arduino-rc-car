#include "rc_system_transmission.h"
#include "transmission_system.h"
#include "constants.h"
#include <Arduino.h>

using namespace rc_system;

//TransmissionSystem transmission(PIN_ENABLE_TRANSMISSION_SYSTEM, PIN_FORWARD_TRANSMISSION_SYSTEM, PIN_BACKWARD_TRANSMISSION_SYSTEM);
RC_System_Transmission transmission;

//---- Sketch ----
void setup() {
  if(Serial) {
    Serial.begin(9600);
  }
}


int i = 0;
void loop() {
  unsigned long current_ms = millis();
  String action = "THROTTLE";
  if(i % 20 == 0) {
      action = "STOP_THROTTLE";
  }
  
  transmission.loop(action, current_ms);
  /*for(int i = 1; i <= transmission.get_number_of_gears(); ++i) {
    transmission.shift_to(i);
    transmission.throttle();

    delay(5000);

    transmission.stop_throttle();*/

    ++i;
}
