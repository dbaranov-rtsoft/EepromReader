#include <string>
#include <iostream>
#include <cstdint>
#include "I2CEepromDevice.h"
#include "EepromData.h"

const std::string eepromFileName = "BinaryEeprom.txt";

int main() {
	I2CEepromDevice eepromI2cDevice(eepromFileName);

	EepromData eepromData;
	bool isOk = eepromI2cDevice.read(eepromData);
	if (!isOk) {
		return -1;
	}

	eepromData.print();

	return 1;
}

