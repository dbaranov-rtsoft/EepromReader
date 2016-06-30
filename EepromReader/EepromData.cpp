#include <iostream>
#include <string>
#include "EepromData.h"

void EepromData::print() [[suppress(type.1)]] {
	std::cout
		<< "Version: " << data.version << std::endl
		<< "Serial number: " << data.serialNumber << std::endl
		<< "Product name: " << std::string(reinterpret_cast<char*>(&data.productName[0]), sizeof(data.productName)) << std::endl
		<< "Manufacturer: " << std::string(reinterpret_cast<char*>(&data.manufacturer[0]), sizeof(data.manufacturer)) << std::endl
		<< "Manufacturing date: " << std::string(reinterpret_cast<char*>(&data.manufactoringDate[0]), sizeof(data.manufactoringDate)) << std::endl;
}
