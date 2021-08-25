#include "rfid_system.h"

namespace rc_system {

    const byte UID_CARD[4] = {0x65, 0x33, 0x8F, 0x22}; 
    const byte UID_KEY_CHAIN[4] = {0xAA, 0xE9, 0xF8, 0x3F}; 

    RfidSystem::RfidSystem() : mfrc522(), read_UID(), serial(40,40,false) {
		mfrc522 = MFRC522(PIN_RFID_SYSTEM_SS, PIN_RFID_SYSTEM_RESET);
	}
	
	void RfidSystem::setup(SoftwareSerial& output_serial) {
		SPI.begin();
		mfrc522.PCD_Init();
        serial = output_serial;
	}
	
	void RfidSystem::read_UID_from_card() {
		for(byte i = 0; i < mfrc522.uid.size; ++i) { // UID is 4bytes length
			read_UID[i] = mfrc522.uid.uidByte[i];
		}
	}
	
	boolean RfidSystem::equals_UID(byte UID_1[], byte UID_2[]) const {
		byte i = 0;
		while(i < mfrc522.uid.size) {
			if(UID_1[i] != UID_2[i]) {
				return false;      
			}
			++i;
		}
		return true;
	}
	
	bool RfidSystem::try_to_read_UID() {
		// If there is a card present and it's possible to get data from it
		if(mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
			read_UID_from_card();
			mfrc522.PICC_HaltA(); // It's not necessary to read more data, so stop communication
			
			if(equals_UID(read_UID, UID_CARD)) {
                serial.write(RFID_SYSTEM_CARD_CODE);
                return true;
			} else if(equals_UID(read_UID, UID_KEY_CHAIN)) {
                serial.write(RFID_SYSTEM_KEY_CHAIN_CODE);
                return true;
			}
		}
        return false;
    }

}
