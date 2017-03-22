#include "stdafx.h"
#include "Solution.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <valarray>

/* 14. Longest Common Prefix */
std::string Solution::longestCommonPrefix(std::vector<std::string>& strs)
{
	if (strs.size() == 0)
		return "";
	std::string ans = *strs.begin();
	for (std::vector<std::string>::iterator itr = strs.begin(); (itr + 1) != strs.end(); ++itr)
	{
		std::cout << ans << std::endl;
		for (int j = 0; j < ans.length(); j++)
		{
			if ((*itr)[j] == (*(itr + 1))[j])
				continue;
			else
				ans = ans.substr(0, j);
		}
	}
	return ans;
}

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

/* 67. Add Binary */
std::string Solution::addBinary(std::string a, std::string b)
{
	long long _a = 0, _b = 0, carry = 0;
	std::string ans;
	for (int i = 0; i < a.length() || i < b.length(); i++)
	{
		std::cout << a[a.length() - i - 1] << " " << b[b.length() - i - 1] << " " << carry << std::endl;
		if (i < a.length() && i < b.length())
		{
			if (a[a.length() - i - 1] + b[b.length() - i - 1] - 96 + carry > 1)
			{
				ans.insert(0, std::to_string(a[a.length() - i - 1] + b[b.length() - i - 1] - 96 + carry - 2));
				carry = 1;
			}
			else
			{
				ans.insert(0, std::to_string(a[a.length() - i - 1] + b[b.length() - i - 1] - 96 + carry));
				carry = 0;
			}
		}
		else if (i < a.length())
		{
			if (a[a.length() - i - 1] - 48 + carry > 1)
			{
				ans.insert(0, std::to_string(a[a.length() - i - 1] - 48 + carry - 2));
				carry = 1;
			}
			else
			{
				ans.insert(0, std::to_string(a[a.length() - i - 1] - 48 + carry));
				carry = 0;
			}
		}
		else
		{
			if (b[b.length() - i - 1] - 48 + carry > 1)
			{
				ans.insert(0, std::to_string(b[b.length() - i - 1] - 48 + carry - 2));
				carry = 1;
			}
			else
			{
				ans.insert(0, std::to_string(b[b.length() - i - 1] - 48 + carry));
				carry = 0;
			}
		}
	}
	if (carry == 1)
		ans.insert(0, "1");
	return ans;
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

/* 386. Lexicographical Numbers */
std::vector<int> Solution::lexicalOrder(int n)
{
	std::vector<int> ans;
	//1 10 100 101 102 ... 11 110 111 ...//123
	int k = 0;
	for (int i = 1, j = 0; j < n; j++)
	{
		std::cout << i << std::endl;
		ans.push_back(i);
		if (i * 10 <= n)
			i *= 10;
		else if (i + 1 > n)
		{
			i /= 10;
			i++;
			while (i % 10 == 0)
			{
				i /= 10;
			}
		}
		else if ((i + 1) % 10 != 0)
			i++;
		else
		{
			i++;
			while (i / 10 > 0 && i % 10 == 0)
			{
				i /= 10;
			}
		}
	}
	return ans;
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

/* 461. Hamming Distance */
int Solution::hammingDistance(int x, int y)
{
	int z = x ^ y, ans = 0;
	while (z > 0)
	{
		if (z % 2 != 0)
			ans++;
		z /= 2;
	}
	return ans;
}

/* 476. Number Complement */
int Solution::findComplement(int num)
{
	std::vector<int> ans;
	int _ans = 0;
	while (num > 0)
	{
		if (num % 2 != 0)
			ans.push_back(0);
		else
			ans.push_back(1);
		num /= 2;
	}
	for (int i = 0; i < ans.size(); i++)
	{
		std::cout << ans[i] << std::endl;
	}
	for (int i = 0; i < ans.size(); i++)
	{
		_ans += ans[i] * pow(2, i);
	}
	return _ans;
}

/* 500. Keyboard Row */
std::vector<std::string> Solution::findWords(std::vector<std::string>& words)
{
	std::map<char, int> dict;
	char row0[] = {'q','w','e','r','t','y','u','i','o','p','Q','W','E','R','T','Y','U','I','O','P'},
		row1[] = {'a','s','d','f','g','h','j','k','l','A','S','D','F','G','H','J','K','L'},
		row2[] = {'z','x','c','v','b','n','m','Z','X','C','V','B','N','M'};
	for (char a : row0)
	{
		dict[a] = 0;
	}
	for (char a : row1)
	{
		dict[a] = 1;
	}
	for (char a : row2)
	{
		dict[a] = 2;
	}
	std::vector<std::string> ans;
	for (std::vector<std::string>::iterator itr = words.begin(); itr != words.end(); ++itr)
	{
		int group = dict[(*itr)[0]];
		if (itr->size() < 2)
			ans.push_back(*itr);
		else
			for (int i = 1; i < itr->size(); i++)
			{
				if (group != dict[(*itr)[i]])
					break;
				else if (i == itr->size() - 1)
					ans.push_back(*itr);
			}
	}
	return ans;
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
