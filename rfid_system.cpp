#include "rfid_system.h"

namespace rc_system {

    const byte UID_CARD[4] = {0x65, 0x33, 0x8F, 0x22}; 
    const byte UID_KEY_CHAIN[4] = {0xAA, 0xE9, 0xF8, 0x3F}; 

    RFID_System::RFID_System() {
		mfrc522 = MFRC522(PIN_RFID_SYSTEM_SS, PIN_RFID_SYSTEM_RESET);
	}
	
	void RFID_System::setup() {
		SPI.begin();
		mfrc522.PCD_Init();
	}
	
	void RFID_System::read_UID_from_card() {
		for(byte i = 0; i < mfrc522.uid.size; ++i) { // UID is 4bytes length
			read_UID[i] = mfrc522.uid.uidByte[i];
		}
	}
	
	boolean RFID_System::equals_UID(byte UID_1[], byte UID_2[]) const {
		byte i = 0;
		while(i < mfrc522.uid.size) {
			if(UID_1[i] != UID_2[i]) {
				return false;      
			}
			++i;
		}
		return true;
	}
	
	void RFID_System::loop(SoftwareSerial serial) {
		// If there is a card present and it's possible to get data from it
		if(mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
			read_UID_from_card();
			mfrc522.PICC_HaltA(); // It's not necessary to read more data, so stop communication
			
			if(equals_UID(read_UID, UID_CARD)) {
                serial.write(CARD_CODE);
			} else if(equals_UID(read_UID, UID_KEY_CHAIN)) {
				// TODO: send via bluetooth
                serial.write(KEY_CHAIN_CODE);
			}
		}
    }

}
