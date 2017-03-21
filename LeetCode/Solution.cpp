#include "stdafx.h"
#include "Solution.h"
#include <algorithm>
#include <vector>
#include <iostream>


/* 20. Valid Parentheses */
bool Solution::isValid(std::string s)
{
	std::vector<char> arr;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			arr.push_back(s[i]);
		}
		else if (arr.size() == 0)
		{
			return false;
		}
		else if (s[i] == ')')
		{
			if (*arr.rbegin() != '(')
				return false;
			arr.pop_back();
		}
		else if (s[i] == '}')
		{
			if (*arr.rbegin() != '{')
				return false;
			arr.pop_back();
		}
		else if (s[i] == ']')
		{
			if (*arr.rbegin() != '[')
				return false;
			arr.pop_back();
		}
		else
			return false;
	}
	if (arr.size() != 0)
		return false;
	return true;
}

/* 125. Valid Palindrome */
bool Solution::isPalindrome(std::string s)
{
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
	std::vector<char> arr;
	for (int i = 0; i < s.length(); i++)
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
			arr.push_back(s[i]);
	}
	std::vector<char>::reverse_iterator itrr = arr.rbegin();
	for (std::vector<char>::iterator itr = arr.begin(); itr != arr.end(); ++itr , ++itrr)
	{
		if (*itr != *itrr)
			return false;
	}
	return true;
}

/* 345. Reverse Vowels of a String */
std::string Solution::reverseVowels(std::string s)
{
	std::vector<int> arr;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
			s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
		{
			arr.push_back(i);
		}
	}

	std::vector<int>::reverse_iterator itrr = arr.rbegin();
	char temp;
	int count = arr.size() / 2;
	for (std::vector<int>::iterator itr = arr.begin(); itr != arr.end() && count != 0; ++itr , --count)
	{
		std::cout << *itr << " " << *itrr << std::endl;
		temp = s[*itr];
		s[*itr] = s[*itrr];
		s[*itrr] = temp;
		++itrr;
	}
	return s;
}

/* 459. Repeated Substring Pattern */
bool Solution::repeatedSubstringPattern(std::string s)
{
	std::string temp;
	for (int i = s.length() / 2; i > 0; i--)
	{
		std::cout << s.length() << " " << i << " " << s.length() % i << std::endl;
		if (s.length() % i != 0)
			continue;
		temp = s.substr(0, i);
		for (int j = 0; j < s.length(); j += temp.length())
		{
			std::cout << temp << " " << s.substr(j, temp.length()) << " " << j << std::endl;
			if (temp != s.substr(j, temp.length()))
				break;
			if (j == s.length() - temp.length())
				return true;
		}
	}
	return false;
}

/* 520. Detect Capital */
bool Solution::detectCapitalUse(std::string word)
{
	if (word.length() == 0)
		return true;
	bool allCap = false;
	if (isCapital(word[0]))
	{
		for (int i = 1; i < word.length(); i++)
		{
			if (i == 1)
				allCap = isCapital(word[i]);
			else
			{
				if (isCapital(word[i]) != allCap)
					return false;
			}
		}
	}
	else
	{
		for (int i = 1; i < word.length(); i++)
		{
			if (isCapital(word[i]) != allCap)
				return false;
		}
	}
	return true;
}

/* util for 520. */
bool Solution::isCapital(char s)
{
	if (s >= 'A' && s <= 'Z')
		return true;
	return false;
}
