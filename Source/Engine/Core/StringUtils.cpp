#include "StringUtils.h"
#include <cstring>

namespace nc
{
	std::string nc::StringUtils::ToUpper(const std::string& str)
	{
		string newString = "";
		for (int i = 0; i < str.length(); i++) {
			newString += toupper(str.at(i));
		}
		return newString;
	}

	std::string nc::StringUtils::ToLower(const std::string& str)
	{
		string newString = "";
		for (int i = 0; i < str.length(); i++) {
			newString += tolower(str.at(i));
		}
		return newString;
	}

	bool nc::StringUtils::IsEqualIgnoreCase(const std::string& stringOne, const std::string& stringTwo)
	{
		return ToLower(stringOne) == ToLower(stringTwo);
	}

	std::string nc::StringUtils::CreateUnique(const std::string& str)
	{
		static uint32_t unique = 0;

		return str + std::to_string(unique++);
	}
}