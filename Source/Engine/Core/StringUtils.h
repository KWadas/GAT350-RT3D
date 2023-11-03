#pragma once
#include <string>
using namespace std;

namespace nc
{
	class StringUtils
	{
	public:
		StringUtils() = default;

	public:
		std::string ToUpper(const std::string& str);
		std::string ToLower(const std::string& str);
		bool IsEqualIgnoreCase(const std::string& stringOne, const std::string& stringTwo);
		std::string CreateUnique(const std::string& str);
	};
}