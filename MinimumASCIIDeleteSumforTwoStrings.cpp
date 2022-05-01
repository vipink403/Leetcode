//https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <iterator> 
#include <string>
#include <numeric>
#include <functional>   // std::not1
#include <algorithm>    // std::count_if
using namespace std;

#define MAX_STRING_SIZE 1001

class Solution_version {
public:
	long long unsigned ASCIISum(const string& str)
	{
		long long unsigned sum = 0;

		for (auto ch : str)
			sum += ch;

		return sum;
	}

	string LCS(string& s1, string& s2)
	{
		vector<vector<int>> dp(MAX_STRING_SIZE, vector<int>(MAX_STRING_SIZE, 0));
		string result = "";
		size_t i, j;

		for (i = 1; i <= (int)s1.size(); i++)
		{
			for (j = 1; j <= (int)s2.size(); j++)
			{
				if (s1[i - 1] == s2[j - 1])
					dp[i][j] = 1 + dp[i - 1][j - 1];
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}

		i = (int)s1.size();
		j = (int)s2.size();

		while (i > 0 && j > 0)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				result += s1[i - 1];
				--i;
				--j;
			}
			else if (dp[i - 1][j] > dp[i][j - 1])
				--i;
			else
				--j;
		}

		return result;
	}

	int minimumDeleteSum(string s1, string s2)
	{
		string lcs = LCS(s1, s2);
		reverse(lcs.begin(), lcs.end());
		cout << lcs << endl;

		int result = ASCIISum(s1) - ASCIISum(lcs);
		result += ASCIISum(s2) - ASCIISum(lcs);
		return result;
	}
};

class Solution{
public:
	long long unsigned ASCIISum(const string& str)
	{
		long long unsigned sum = 0;

		for (auto ch : str)
			sum += ch;

		return sum;
	}

	long long minimumDeleteSum(string s1, string s2)
	{
		vector<vector<int>> dp(MAX_STRING_SIZE, vector<int>(MAX_STRING_SIZE, 0));
		long long result = 0;
		size_t i, j;

		for (i = 1; i <= (int)s1.size(); i++)
		{
			for (j = 1; j <= (int)s2.size(); j++)
			{
				if (s1[i - 1] == s2[j - 1])
					// why 2*s1[i-1] because sum of ascii of lcs will be subtracted from sum of ascii of s1 and s2.
					// i.e sum_acsii(s1) + sum_acsii(s2) - 2*sum_acsii(lcs)
					dp[i][j] = dp[i - 1][j - 1] + 2 * s1[i - 1];
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}

		for (i = 0; i <= (int)s1.size(); i++)
		{
			for (j = 0; j <= (int)s2.size(); j++)
			{
				cout << dp[i][j] << " ";
			}
			cout << endl;
		}

		//int sum1 = std::accumulate(s1.begin(), s1.end(), result);
		//int sum2 = std::accumulate(s2.begin(), s2.end(), result);
		return ASCIISum(s1) + ASCIISum(s2) - dp[s1.size()][s2.size()];
	}
};

int main_minimumDeleteSum()
{
	Solution sln;
	//cout << sln.minimumDeleteSum("sea", "eat") << endl;
	cout << sln.minimumDeleteSum("delete", "leet") << endl;
	return 0;
}