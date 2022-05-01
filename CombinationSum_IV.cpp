//https://leetcode.com/problems/combination-sum-iv/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

template<typename T>
void print(T& container)
{
	for (auto num : container)
	{
		cout << num << " ";
	}
	cout << endl;
}

class Solution {
public:
	vector<vector<int>> final_result;
	unordered_map<int, int> memo;

	void combinationSum4HelperPrint(vector<int>& nums, int target, vector<int> output, int start)
	{
		//cout << target << endl;
		if (target == 0)
		{
			final_result.push_back(output);
			return;
		}

		if (target < 0)
			return;

		for (size_t index = 0; index < nums.size(); index++)
		{
			if (nums[index] <= target)
			{
				output.push_back(nums[index]);
				combinationSum4HelperPrint(nums, target - nums[index], output, index);
				output.pop_back();
			}
		}
	}

	int combinationSum4Helper(vector<int>& nums, int target)
	{
		//cout << target << endl;
		if (target == 0)
			return 1;

		if (target < 0)
			return 0;

		if (memo.find(target) != memo.end())
			return memo[target];

		int result = 0;
		for (size_t index = 0; index < nums.size(); index++)
		{
			if (nums[index] <= target)
			{
				result += combinationSum4Helper(nums, target - nums[index]);
			}
		}
		return memo[target] = result;
	}

	int combinationSum4(vector<int>& nums, int target)
	{
		vector<int> output;
		return combinationSum4Helper(nums, target);
	}

	int main()
	{
		Solution sln;
		vector<int> vec = { 1, 2, 3 };
		cout << sln.combinationSum4(vec, 4) << endl;
		for (auto couple : sln.memo)
			cout << couple.first << " " << couple.second << endl;
		return 0;
	}
};

