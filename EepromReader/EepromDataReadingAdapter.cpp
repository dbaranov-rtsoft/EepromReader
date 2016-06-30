#include <string>
#include <fstream>
#include <iostream>
#include <cstdint>
#include <boost\noncopyable.hpp>
#include "EepromDataReadingAdapter.h"
#include "EepromData.h"

EepromDataReadingAdapter::EepromDataReadingAdapter(std::string eepromPath) : eepromPath(eepromPath) {}

bool EepromDataReadingAdapter::open() noexcept {
	if (eepromInputfile.is_open()) {
		eepromInputfile.close();
	}

	eepromInputfile.open(eepromPath, std::ios::binary);

	return eepromInputfile.good();
}

bool EepromDataReadingAdapter::readByte(uint8_t& byte) noexcept [[suppress(type.1)]]{
	if (eepromInputfile.good()) {
		eepromInputfile.read(reinterpret_cast<char*>(&byte), 1);
		return static_cast<bool>(eepromInputfile);
	}

	return false;
}
