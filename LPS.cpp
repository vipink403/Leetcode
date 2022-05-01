//https://leetcode.com/problems/longest-palindromic-substring/

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <iterator> 
#include <string>
#include <filesystem>
#include <functional>   // std::not1
#include <algorithm>    // std::count_if
using namespace std;

#define MAX_STRING_SIZE 1001

class Solution {
	vector<vector<int>> dp;
public:

	string longestPalindrome(string s)
	{
		dp.resize(MAX_STRING_SIZE, vector<int>(MAX_STRING_SIZE, 0));

		int i, j, str_size = (int)s.size();
		string t(s);
		reverse(t.begin(), t.end());

		for (i = 0; i <= str_size; i++)
		{
			for (j = 0; j <= str_size; j++)
			{
				if (i == 0 || j == 0)
				{
					dp[i][j] = 0;
					continue;
				}
				if (s[i - 1] == t[j - 1])
					dp[i][j] = 1 + dp[i - 1][j - 1];
				else
					dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}

		for (int i = 0; i <= str_size; i++)
		{
			for (int j = 0; j <= str_size; j++)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}

		string ans = "";
		i = j = str_size;
		while (i>0 && j>0)
		{
			if (s[i - 1] == t[j - 1])
			{
				ans += s[i - 1];
				--i;
				--j;
			}
			else if (dp[i][j - 1] > dp[i - 1][j])
				--j;
			else
				--i;
		}

		reverse(ans.begin(), ans.end());
		return ans;
	}
};

int main_LPS()
{
	Solution sln;
	cout << sln.longestPalindrome("babad") << endl;
	return 0;
}