//https://leetcode.com/problems/best-time-to-buy-and-sell-stock//

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
public:
	// Extra space solution
	int maxProfit2(vector<int>& prices) 
	{
		vector<int> min_so_far;

		min_so_far.resize(prices.size());

		min_so_far[0] = prices[0];
		for (int i = 1; i < prices.size(); i++)
			min_so_far[i] = std::min(prices[i], min_so_far[i-1]);

		int result = INT_MIN;
		for (int i = 0; i < prices.size(); i++)
			result = std::max(result, prices[i] - min_so_far[i]);

		return result < 0 ? 0 : result;
	}

	// Constant Space
	int maxProfit1(vector<int>& prices)
	{
		int min_so_far = INT_MAX, maxprofit = 0;
		for (size_t i = 0; i < prices.size(); i++)
		{
			maxprofit = max(maxprofit, prices[i] - min_so_far);
			min_so_far = min(min_so_far, prices[i]);
		}
		return maxprofit;
	}

	// Very efficient Solution
	int maxProfit(vector<int>& prices)
	{
		int min_so_far = prices[0], maxprofit = 0;
		for (size_t i = 1; i < prices.size(); i++)
		{
			if (prices[i] < prices[i - 1])
				min_so_far = min(min_so_far, prices[i]);
			else
				maxprofit = max(maxprofit, prices[i] - min_so_far);
		}
		return maxprofit;
	}
};

int main_buy_sell_max_profit_I()
{
	vector<int> prices = { 2, 4, 1 };
	Solution sln;
	cout << sln.maxProfit(prices) << endl;
	return 0;
}
