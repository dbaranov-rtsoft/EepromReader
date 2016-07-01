#include <iostream>
#include <iomanip>
#include <string>
#include "EepromData.h"

void EepromData::print() const [[suppress(type.1)]] {
	std::cout
		<< "Version: " << data.version << std::endl
		<< "Serial number: " << data.serialNumber << std::endl
		<< "Product name: " << std::string(reinterpret_cast<const char*>(&data.productName[0]), sizeof(data.productName)) << std::endl
		<< "Manufacturer: " << std::string(reinterpret_cast<const char*>(&data.manufacturer[0]), sizeof(data.manufacturer)) << std::endl
		<< "Manufacturing date: " << std::string(reinterpret_cast<const char*>(&data.manufactoringDate[0]), sizeof(data.manufactoringDate)) << std::endl;

	printAsHex();
}

void EepromData::printAsHex() const {
	for (uint8_t byte : bytes) {
		std::cout << std::hex << std::setfill('0') << std::setw(2) << "0x" << static_cast<int>(byte) << " ";
	}
	std::cout << std::endl;
}
