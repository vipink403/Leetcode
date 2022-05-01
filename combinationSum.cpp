//https://leetcode.com/problems/combination-sum/

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

/*Time Complexity: O(Length of Array ^ TargetSum)
	Or O(2^Length of Array)
*/

class Solution {
	vector<vector<int>> final_result;
public:
	void knapsack(vector<int>& nums, vector<int> output, int target, int index)
	{
		if (target < 0 || index < 0)
			return;

		if (target == 0)
		{
			final_result.push_back(output);
			return;
		}

		if (nums[index] <= target)
		{
			// exclude current item
			knapsack(nums, output, target, index - 1);

			// include current item
			output.push_back(nums[index]);
			knapsack(nums, output, target - nums[index], index);
		}
		else
		{
			// exclude current item
			knapsack(nums, output, target, index - 1);
		}
	}

	vector<vector<int>>& combinationSum(vector<int>& nums, int target)
	{
		vector<int> output;
		knapsack(nums, output, target, (int)nums.size() - 1); 
		return final_result;
	}

	int main()
	{
		Solution sln;
		vector<int> vec = { 2, 3, 6, 7 };
		auto cont2 = sln.combinationSum(vec, 7);
		for (auto& cont : cont2)
		{
			for (auto num : cont)
			{
				cout << num << " ";
			}
			cout << endl;
		}
		return 0;
	}
};
