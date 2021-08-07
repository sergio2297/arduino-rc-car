#ifndef rfid_system_h_
#define rfid_system_h_

#include <SPI.h>
#include <MFRC522.h>
#include <SoftwareSerial.h>
#include "constants.h"

namespace rc_system {

    class RFID_System {
        public:
            RFID_System();
			
			void setup();
            void loop(SoftwareSerial serial);

        private:		
			MFRC522 mfrc522;
			byte read_UID[4];
		
			void read_UID_from_card();
			boolean equals_UID(byte UID1[], byte UID_2[]) const;
    };
}

#endif
