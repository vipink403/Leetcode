//https://leetcode.com/problems/palindrome-partitioning-ii

// C++ Code for Palindrome Partitioning
#include <iostream>
#include <stack>
#include <string>
#include <climits>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define sz 2001
#define max_sz 1001

class Solution
{
public:
	unordered_map<string, int> memo;
	//Function to return max value that can be put in knapsack of capacity W.
	int knapSackHelper(int cap, int wt[], int val[], int n)
	{
		if (n < 0 || cap == 0) return 0;

		string key = to_string(cap);
		key += '|';
		key += to_string(n);

		if (memo.find(key) != memo.end())
			return memo[key];

		if (wt[n] <= cap)
			return memo[key] = max(val[n] + knapSackHelper(cap - wt[n], wt, val, n - 1),
											knapSackHelper(cap, wt, val, n - 1));
		else
			return memo[key] = knapSackHelper(cap, wt, val, n - 1);
	}

	int knapSack(int cap, int wt[], int val[], int n)
	{
		memo.clear();
		return knapSackHelper(cap, wt, val, n - 1);
	}
};

// { Driver Code Starts.

int main_knapSack()
{
	int val[] = { 51, 94, 66, 55, 81, 99, 79, 12, 14, 32, 36, 88, 65, 79, 62, 37, 47, 13, 93, 77, 100, 26, 44, 66, 73, 71, 74, 27, 6, 43, 16, 50, 7, 65, 3, 58, 7, 90, 99, 60, 84, 54, 68, 45, 28, 5, 43, 77, 47, 68, 9, 83, 66, 20, 84, 67, 4, 70, 90, 80, 11, 72, 54, 63, 9, 91, 43, 44, 36, 89, 60, 92, 70, 13, 66, 43, 45, 20, 32, 22, 61, 94, 25, 79, 27 };
	int wt[] = { 6, 89, 12, 23, 22, 72, 2, 25, 47, 40, 51, 93, 15, 49, 85, 43, 88, 75, 96, 72, 72, 26, 90, 46, 17, 69, 74, 73, 7, 25, 35, 27, 7, 19, 77, 53, 11, 21, 20, 32, 39, 45, 24, 19, 54, 94, 85, 9, 38, 19, 40, 37, 40, 53, 62, 32, 47, 20, 19, 51, 90, 5, 89, 50, 68, 63, 59, 8, 64, 16, 24, 51, 13, 37, 76, 63, 68, 32, 12, 18, 12, 60, 45, 39, 64 };
	Solution ob;
	ob.memo.clear();
	cout << ob.knapSack(50, wt, val, 85) << endl;
	return 0;
}  // } Driver Code Ends