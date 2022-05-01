//https://leetcode.com/problems/word-break-ii/

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
	unordered_map<string, vector<string>> memo;
public:

	vector<string> wordBreak(string &s, unordered_set<string>& wordDict)
	{
		vector<string> results;
		if (s.empty())
			return results;

		if (wordDict.find(s) != wordDict.end())
			results.push_back(s);

		if (memo.find(s) != memo.end())
			return memo[s];

		for (int k = 1; k <= (int)s.length(); k++)
		{
			string left = s.substr(0, k);
			if (wordDict.find(left) != wordDict.end())
			{
				string right = s.substr(k);
				vector<string> substrings = wordBreak(right, wordDict);
				for (auto substring : substrings)
					results.push_back(left + " " + substring);
			}
		}
		return memo[s] = results;
	}

	vector<string> wordBreak(string s, vector<string>& wordDict)
	{
		unordered_set<string> dict(wordDict.begin(), wordDict.end());
		string output;
		return wordBreak(s, dict);
	}

	int main()
	{
		Solution sln;
		vector<string> dict = { "apple", "pen", "applepen", "pine", "pineapple" };
		auto container = sln.wordBreak("pineapplepenapple", dict);
		//vector<string> dict = { "leet", "code"};
		//auto container = sln.wordBreak("leetcode", dict);
		print(container);
		return 0;
	}
};

