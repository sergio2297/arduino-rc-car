#ifndef rfid_system_h_
#define rfid_system_h_

#include <SPI.h>
#include <MFRC522.h>
#include <SoftwareSerial.h>
#include "constants.h"

namespace rc_system {

    class RfidSystem {
        public:
            RfidSystem();
			
			void setup(SoftwareSerial& output_serial);
            bool try_to_read_UID();

        private:		
			MFRC522 mfrc522;
			byte read_UID[4];
            SoftwareSerial serial;
		
			void read_UID_from_card();
			boolean equals_UID(byte UID1[], byte UID_2[]) const;
    };
}

#endif
