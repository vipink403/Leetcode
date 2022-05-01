//https://leetcode.com/problems/palindrome-partitioning-ii

// C++ Code for Palindrome Partitioning
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define sz 2001
#define max_sz 1001

namespace PalindromePartition
{
	class Solution
	{
		int memo[sz][sz];
	public:
		Solution()
		{
			cout << "Ctor called" << endl;
		}

		bool isPalindrome(string& str, int i, int j)
		{
			while (i < j)
			{
				if (str[i++] != str[j--])
					return false;
			}
			return true;
		}

		int minPalPartionOptimized(string& str, int i, int j)
		{
			cout << i << " " << j << endl;
			if (memo[i][j] != -1)
				return memo[i][j];

			// Base case - Single character is a palindrome
			if (i >= j || isPalindrome(str, i, j))
				return  memo[i][j] = 0;

			int result = INT_MAX;

			// Time Limit Exceeds in Leetcode for one test case
			/*for (int k = i; k < j; k++)
			{
			if (isPalindrome(str, i, k) == false)
			continue;

			int left = (memo[i][k] == -1) ? minPalPartionOptimized(str, i, k) : memo[i][k];
			int right = (memo[k + 1][j] == -1) ? minPalPartionOptimized(str, k + 1, j) : memo[k + 1][j];
			result = min(result, left + right + 1);
			}*/

			for (int k = i; k < j; k++)
			{
				if (isPalindrome(str, i, k) == false)
					continue;
				/*
				the first intuition was getting a TLE even after deploying memoization. It gave me the idea that there is still a need to reduce a few checks. Going deeper I visualized that when LEFT substring results as NON-PALINDROME then there is no need to check the right substring since it's not gonna make any difference and the final memower will still remain FALSE even if the right substring comes out to be a palindrome. So, the current cut/partition would not be valid and so we skip to the next iteration.

				Also, this optimization(which usually is overlooked while writing recursive code) can be deployed in various MCM based DP questions and is an extremely good point to make in f2f interviews, when there are no compilers to compile the code and check for TLE.

				To minimize the redundant checks, we are not considering to check when left part is not palindrome. Because in the final result a | bcccb - we will only make a cut if the left part is sure shot palindrome and calculate the right part. For abcc - a | bcc (left = 0 , right = 1) minimum = left + right + 1. If we try to choose to make a cut on left if not palindrome then ab | cc, we will be ending with redundant check -> a | b (this is pre-calculated) and cc (already calculated on first check). (on the end of the recursive call you are still figuring if the left part is palindrome)
				*/
				if (isPalindrome(str, i, k))
				{
					int right = (memo[k + 1][j] == -1) ? minPalPartionOptimized(str, k + 1, j) : memo[k + 1][j];
					result = min(result, right + 1);
				}
			}
			return memo[i][j] = result;
		}

		int minCut(string str)
		{
			memset(memo, -1, sizeof(memo));
			return minPalPartionOptimized(str, 0, (int)str.size() - 1);
		}
	};
};

class Solution
{
	vector<vector<string>> palindromePartitionings;

public:
	Solution()
	{
		cout << "Ctor called" << endl;
	}

	bool ispalindrome(const string &s)
	{
		int i = 0, j = s.size() - 1;
		while (i < j)
		{
			if (s[i++] != s[j--])
				return false;
		}
		return true;
	}

	bool ispalindrome(string& str, int i, int j)
	{
		while (i < j)
		{
			if (str[i++] != str[j--])
				return false;
		}
		return true;
	}

	void partition(string str, vector<string>& output)
	{
		if (str.empty())
		{
			palindromePartitionings.push_back(output);
			return;
		}

		for (size_t i = 1; i <= (int)str.length(); i++)
		{
			// choose
			string left = str.substr(0, i);
			string right = str.substr(i);
			if (ispalindrome(left))
			{
				//vector<string> temp(output);
				output.push_back(left);
				//temp.push_back(left);
				partition(right, output);
				output.pop_back();
			}
		}
	}

	vector<vector<string>> partition(string s)
	{
		vector<string> output;
		partition(s, output);
		return palindromePartitionings;
	}

	int main()
	{
		//string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
		//Solution ob;
		//cout << ob.minCut(str) << "\n";

		string s("missippi");
		Solution sln;
		auto results = sln.partition(s);
		for (auto cont : results)
		{
			for (auto item : cont)
				cout << item << " ";
			cout << endl;
		}

		/* for (size_t i = 1; i < s.length(); i++)
		{
		string left = s.substr(0, i);
		string right = s.substr(i);
		cout << left << " " << right << endl;
		}*/

		return 0;
	}
};
