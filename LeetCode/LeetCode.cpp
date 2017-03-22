// LeetCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Solution.h"

using namespace std;

int main()
{
	vector<string> x;
	x.push_back("Hello");
	x.push_back("Alaska");
	x.push_back("Dad");
	x.push_back("Peace");
	for (string a : Solution::findWords(x))
	{
		cout << a << endl;
	}
//	cout << Solution::findWords(x) << endl;
	system("pause");
	return 0;
}
