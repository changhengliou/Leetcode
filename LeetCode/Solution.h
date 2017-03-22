#pragma once
#include <string>
#include <vector>

class Solution
{
public:
	/* 14. Longest Common Prefix */
	static std::string longestCommonPrefix(std::vector<std::string>& strs);
	/* 20. Valid Parentheses */
	static bool isValid(std::string s);
	/* 67. Add Binary */
	static std::string addBinary(std::string a, std::string b);
	/* 125. Valid Palindrome */
	static bool isPalindrome(std::string s);
	/* 345. Reverse Vowels of a String */
	static std::string reverseVowels(std::string s);
	/* 386. Lexicographical Numbers(Required) */
	static std::vector<int> lexicalOrder(int n);
	/* 459. Repeated Substring Pattern(Required) */
	static bool repeatedSubstringPattern(std::string s);
	/* 461. Hamming Distance */
	static int hammingDistance(int x, int y);
	/* 476. Number Complement */
	static int findComplement(int num);
	/* 500. Keyboard Row */
	static std::vector<std::string> findWords(std::vector<std::string>& words);
	/* 520. Detect Capital */
	static bool detectCapitalUse(std::string word);
	/* util for 520. */
	static bool isCapital(char s);
};
