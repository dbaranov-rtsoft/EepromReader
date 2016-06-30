#pragma once

#include <cstdint>

#pragma pack(push, 1)
struct EepromDataStruct {
	uint64_t version;
	uint64_t serialNumber;
	uint8_t productName[16];
	uint8_t manufacturer[16];
	uint8_t manufactoringDate[16];
};
#pragma pack(pop)

static_assert(sizeof(EepromDataStruct) == (4 * 16), "EepromData structure incorrect packing");

union EepromData {
	EepromDataStruct data;
	uint8_t bytes[sizeof(EepromDataStruct)];

	void print();
};