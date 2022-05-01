//https://leetcode.com/problems/generate-parentheses/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

template<typename T>
void print(T& container)
{
	for (auto num : container)
	{
		cout << num << "\n";
	}
	cout << endl;
}

class Solution {
	vector<string> result;
public:
	void generateParenthesis(int open, int close, string& output)
	{
		if (open < 0 || close < 0)
			return;

		if (open == 0 && close == 0)
		{
			result.push_back(output);
			return;
		}

		if (open == close)
		{
			output += '(';
			generateParenthesis(open - 1, close, output);
		}
		else if (open < close)
		{
			string output1(output);
			string output2(output);
			output1 += '(';
			output2 += ')';
			generateParenthesis(open - 1, close, output1);
			generateParenthesis(open, close - 1, output2);
		}
	}

	vector<string>& generateParenthesis(int n)
	{
		string output;
		generateParenthesis(n, n, output);
		return result;
	}

	int main()
	{
		Solution sln;
		int n = 3;
		auto container = sln.generateParenthesis(3);
		print(container);
		return 0;
	}
};
