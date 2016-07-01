#pragma once

#include <string>
#include <fstream>
#include <cstdint>
#include <boost\noncopyable.hpp>

class I2CEepromDevice : boost::noncopyable {
	std::ifstream eepromInputfile;

public:
	explicit I2CEepromDevice(std::string eepromPath) : eepromInputfile(eepromPath, std::ios::binary) {};

	template<typename T>
	bool read(T& data);
};

template<typename T>
bool I2CEepromDevice::read(T& data) {
	static_assert(!std::is_pointer<T>::value, "data shouldn't be pointer");

	if (eepromInputfile.bad()) {
		return false;
	}

	[[suppress(type.1)]] {
		eepromInputfile.read(reinterpret_cast<char*>(&data), sizeof(data));
	}
	return static_cast<bool>(eepromInputfile);
}
