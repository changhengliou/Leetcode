#pragma once
#include <string>

class Solution
{
public:
	/* 20. Valid Parentheses */
	static bool isValid(std::string s);
	/* 125. Valid Palindrome */
	static bool isPalindrome(std::string s);
	/* 345. Reverse Vowels of a String */
	static std::string reverseVowels(std::string s);
	/* 459. Repeated Substring Pattern(Required) */
	static bool repeatedSubstringPattern(std::string s);
	/* 520. Detect Capital */
	static bool detectCapitalUse(std::string word);
	/* util for 520. */
	static bool isCapital(char s);
};
