#include "rc_system_rfid.h"
#include "constants.h"

namespace rc_system {
	
	RC_System_RFID::RC_System_RFID() :
		RC_System(PERIOD_MS_RFID_SYSTEM), rfid(), timestamp(-1) {}

	void RC_System_RFID::setup() {
		// Not funcional.
	}

	void RC_System_RFID::setup(SoftwareSerial& output_serial) {
		rfid.setup(output_serial);
	}

    void RC_System_RFID::out_of_period_actions(unsigned long current_ms) {
		if(current_ms - timestamp >= RFID_SYSTEM_MINIMUM_DELAY_BETWEEN_CHECKS_MS) {
			if(rfid.try_to_read_UID()) {
			    timestamp = current_ms;
			}
		}
	}
    
	void RC_System_RFID::routine(char action) {}
	
}
