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
		static std::string ToUpper(const std::string& str);
		static std::string ToLower(const std::string& str);
		static bool IsEqualIgnoreCase(const std::string& stringOne, const std::string& stringTwo);
		static std::string CreateUnique(const std::string& str);
	};
}