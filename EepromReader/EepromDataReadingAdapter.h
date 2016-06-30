#pragma once

#include <string>
#include <fstream>
#include <cstdint>
#include <boost\noncopyable.hpp>

struct EepromDataStruct;

class EepromDataReadingAdapter : boost::noncopyable {
	const std::string eepromPath;
	std::ifstream eepromInputfile;

public:
	explicit EepromDataReadingAdapter(std::string eepromPath);

	bool open() noexcept;

	bool readByte(uint8_t& byte) noexcept;
};