//https://leetcode.com/problems/different-ways-to-add-parentheses/
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int calculate(int op1, int op2, char op)
	{
		switch (op)
		{
		case '+':
			return op1 + op2;
		case '*':
			return op1 * op2;
		case '-':
			return op1 - op2;
		default:
			break;
		}
		return 0;
	}
	/*
	This problem can be solved using divide and conquer stratergy
	1. Traverse the expression
	2. If we encounter an operator at index 'i', then
	divide it into two parts
	i)  left part = left(0,...i-1)
	ii) right part = right(i+1, ...end)
	these two parts will return results of sub-expression i.e results from substring(0,i-1) and (i+1,end ) respectively
	Since at index i we have an operator , we apply that operation for each element in left to each element in right
	*/
	vector<int> diffWaysToCompute(string exp, unordered_map<string, vector<int>>& memo)
	{
		if (memo.find(exp) != memo.end())
			return memo[exp];

		//cout << exp << endl;
		vector<int> result;
		bool isExpr = false;
		for (size_t index = 0; index < exp.size(); index++)
		{
			// an operator
			if (!isdigit(exp[index]))
			{
				isExpr = true;
				vector<int> leftList = diffWaysToCompute(exp.substr(0, index), memo);
				vector<int> rightList = diffWaysToCompute(exp.substr(index + 1), memo);

				for (auto op1 : leftList)
				{
					for (auto op2 : rightList)
					{
						result.push_back(calculate(op1, op2, exp[index]));
					}
				}
			}
		}
		if (!isExpr)
			result.push_back(stoi(exp));
		return memo[exp] = result;
	}
};

int main_DifferentWaystoAddParentheses()
{
	Solution sln;
	string str = "2*3-4*5";
	unordered_map<string, vector<int>> memo;
	vector<int> results = sln.diffWaysToCompute(str, memo);
	for (auto result : results)
		cout << result << endl;

	return 0;
}
