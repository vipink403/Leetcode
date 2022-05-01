//https://leetcode.com/problems/word-break/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
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
	unordered_map<string, bool> memo;
public:
	bool wordBreak(string& str, unordered_set<string>& dict)
	{
		// return true if the end of the string is reached
		if (str.empty())
			return true;

		if (dict.find(str) != dict.end())
			return true;

		// if the subproblem is already solved, return the cached result
		if (memo.find(str) != memo.end())
			return memo.at(str);

		// Break at each possible index in the string str
		bool flag = false;
		for (int k = 1; k < (int)str.length(); k++)
		{
			// consider all prefixes of the current string
			string left = str.substr(0, k);
			if (dict.find(left) != dict.end()/*wordBreak(left, dict)*/)
			{
				// if the prefix is found in the dictionary, then recur for the suffix
				string right = str.substr(k);
				flag = wordBreak(right, dict);
				if (flag)
				{
					// return true if the string can be segmented
					return memo[str] = flag;
				}
			}
		}
		// return solution to the current subproblem
		return memo[str];
	}

	bool wordBreak(string str, vector<string>& dict)
	{
		unordered_set<string> wordDict(dict.begin(), dict.end());
		return wordBreak(str, wordDict);
	}

	int main()
	{
		Solution sln;
		vector<string> dict = { "leet", "code" };
		cout << sln.wordBreak("leetcode", dict) << endl;
		return 0;
	}
};

