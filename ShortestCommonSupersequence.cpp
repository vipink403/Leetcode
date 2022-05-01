//https://leetcode.com/problems/shortest-common-supersequence/

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
	vector < vector<int>> dp;
public:
	Solution() {}

	string shortestCommonSupersequence(string str1, string str2) 
	{
		string ans;
		int m = strlen(str1.c_str());
		int n = strlen(str2.c_str());
		dp.resize(MAX_STRING_SIZE, vector<int>(MAX_STRING_SIZE, 0));

		for (size_t i = 1; i <= m; i++)
		{
			for (size_t j = 1; j <= n; j++)
			{
				if (str1[i-1] == str2[j-1])
					dp[i][j] = 1 + dp[i - 1][j - 1];
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}

		// "Logic to printing LCS"
		// if str1[x] == str2[y], add str1[x] to the answer and move to (x-1,y-1)
		// else 
		// if dp[x-1][y] > dp[x][y-1], move to (x-1,y) in the the dp table
		// else if dp[x-1][y] <= dp[x][y-1], move to (x,y-1) in the the dp table

		// "Logic to printing Shortest Common Subsequence"
		// if str1[x] == str2[y], add str1[x] to the answer and move to (x-1,y-1)
		// else 
		// if dp[x-1][y] > dp[x][y-1], add str1[x] to the answer and move to (x-1,y) in the the dp table
		// else if dp[x-1][y] <= dp[x][y-1], add str2[y] to the answer and move to (x,y-1) in the the dp table

		for (size_t i = 0; i <= m; i++)
		{
			for (size_t j = 0; j <= n; j++)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}


		int x = m, y = n;
		while (x > 0 && y > 0)
		{
			// if the character's are same, add it to the result and decrement both indices
			if (str1[x - 1] == str2[y - 1])
			{
				ans.push_back(str1[x - 1]);
				--x;
				--y;
			}
			else
			{
				// go the indices where dp table value is greater, but also add the character before moving up or right
				if (dp[x - 1][y] > dp[x][y - 1])
				{
					ans.push_back(str1[x-1]);
					--x;
				}
				else
				{
					ans.push_back(str2[y-1]);
					--y;
				}
			}
		}

		while (x > 0)
			ans.push_back(str1[--x]);

		while (y > 0)
			ans.push_back(str2[--y]);

		reverse(ans.begin(), ans.end());
		return ans;
	}
};

int main_SCS()
{
	Solution sln;
	cout << sln.shortestCommonSupersequence("abac", "cab") << endl;
	//cout << sln.shortestCommonSupersequence("cab", "abac") << endl;
	return 0;
}          