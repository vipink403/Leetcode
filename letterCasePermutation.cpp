//https://leetcode.com/problems/letter-case-permutation/

#include <iostream>
#include <stack>
#include <string>
#include <climits>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;

void DiceSum(int n, int sum, string out)
{
	if (sum == 0 && n == 0)
	{
		cout << out << endl;
		return;
	}

	for (size_t i = 1; i <= 6; i++)
	{
		if (i <= sum)
		{
			string temp(out);
			temp += to_string(i);

			// Explore
			DiceSum(n - 1, sum - i, temp);
		}
	}
}

class Solution {
public:
	void letterCasePermutationHelper(string s, string output, vector<string>& result)
	{
		if (s.empty())
		{
			result.push_back(output);
			return;
		}

		if (isdigit(s[0]))
		{
			string out(output);
			out += s[0];

			// remove the digit from the input
			s.erase(s.begin());
			
			letterCasePermutationHelper(s, out, result);
		}
		else
		{
			string out1(output);
			out1 += tolower(s[0]);

			string out2(output);
			out2 += toupper(s[0]);

			s.erase(s.begin());
			letterCasePermutationHelper(s, out1, result);
			letterCasePermutationHelper(s, out2, result);
		}
	}

	vector<string> letterCasePermutation(string s)
	{
		vector<string> ans;
		letterCasePermutationHelper(s, "", ans);
		return ans;
	}
};

int main_letterCasePermutation()
{
	int n, sum;
	//cin >> n >> sum;
	//DiceSum(n, sum, "");
	Solution sln;
	auto container = sln.letterCasePermutation("a1b1");
	for (auto item : container)
		cout << item << endl;

	return 0;
}