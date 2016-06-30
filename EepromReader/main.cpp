#include <string>
#include <iostream>
#include <cstdint>
#include "EepromDataReadingAdapter.h"
#include "EepromData.h"

const std::string eepromFileName = "BinaryEeprom.txt";

bool ReadEepromData(EepromDataReadingAdapter& eepromAdapter, EepromData& eepromData) noexcept [[suppress(bounds.2)]] {
	for (size_t i = 0; i < sizeof(EepromData); i++) {
		bool isOk = eepromAdapter.readByte(eepromData.bytes[i]);
		if (!isOk) {
			return false;
		}
	}

	return true;
}

int main() {
	EepromDataReadingAdapter eepromAdapter(eepromFileName);
	if (eepromAdapter.open() == false) {
		std::cout << "Can`t open file " << eepromFileName << std::endl;
	}

	EepromData eepromData;
	bool isOk = ReadEepromData(eepromAdapter, eepromData);
	if (!isOk) {
		return -1;
	}

	eepromData.print();

	return 1;
}

