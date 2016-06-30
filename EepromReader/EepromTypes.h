#pragma once

#include <cstdint>

enum class EepromTypes : uint8_t {
	BinaryEeprom = 0xAA,
	PlainTextEeprom = 0xBB,
	Base64EncodedEeprom = 0xCC,
	Undefined
};