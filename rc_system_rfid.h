#ifndef rc_system_rfid_h_
#define rc_system_rfid_h_

#include "rc_system.h"
#include "rfid_system.h"

namespace rc_system {
	
	class RC_System_RFID : public RC_System {
		public:
			RC_System_RFID();
			void setup();
			void setup(SoftwareSerial& output_serial);
		
		protected:
            void out_of_period_actions(unsigned long current_ms);
			void routine(char action);
			
		private:
			RfidSystem rfid;
			unsigned long timestamp;
	};
}

#endif
