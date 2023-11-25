#include "StringUtils.h"
#include <cstring>

namespace nc
{
	std::string StringUtils::ToUpper(const std::string& str)
	{
		string newString = "";
		for (int i = 0; i < str.length(); i++) {
			newString += toupper(str.at(i));
		}
		return newString;
	}

	std::string StringUtils::ToLower(const std::string& str)
	{
		string newString = "";
		for (int i = 0; i < str.length(); i++) {
			newString += tolower(str.at(i));
		}
		return newString;
	}

	bool StringUtils::IsEqualIgnoreCase(const std::string& stringOne, const std::string& stringTwo)
	{
		return ToLower(stringOne) == ToLower(stringTwo);
	}

	std::string StringUtils::CreateUnique(const std::string& str)
	{
		static uint32_t unique = 0;

		return str + std::to_string(unique++);
	}
}