#pragma once
#include <string>

class BoyerMoore
{
private:
	static int badCharacterShift(std::string str);
	static int goodSuffixShift(std::string str);
public:
	static std::string getMatchingPosition(std::string str);
};
