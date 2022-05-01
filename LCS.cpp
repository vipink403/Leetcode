//https://leetcode.com/problems/longest-common-subsequence

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
//namespace LCS
//{
	class Solution {
		vector < vector<int>> dp;
	public:
		Solution() {}

		int longestCommonSubsequence(string text1, string text2) {
			int m = strlen(text1.c_str());
			int n = strlen(text2.c_str());
			dp.resize(m + 1, vector<int>(n + 1, 0));

			for (size_t i = 1; i <= m; i++)
			{
				for (size_t j = 1; j <= n; j++)
				{
					if (text1[i - 1] == text2[j - 1])
						dp[i][j] = 1 + dp[i - 1][j - 1];
					else
						dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}

			for (int i = 0; i <= m; i++)
			{
				for (int j = 0; j <= n; j++)
				{
					cout << dp[i][j] << " ";
				}
				cout << endl;
			}

			return dp[m][n];
		}
	};

	int main_LCS()
	{
		Solution sln;
		cout << sln.longestCommonSubsequence("abcdcbdbcfdfc", "cfdfcbdbcdcba") << endl;
		return 0;
	}
//}