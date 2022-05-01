//https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

template<typename T>
void print(const T& container)
{
	for (const auto num : container)
	{
		cout << num << " ";
	}
	cout << endl;
}

#define max_size 17

class Solution {
	vector<bool> visited;

public:
	vector<vector<int>> all_solution;
	//bool canPartitionKSubsets(vector<int>& nums, int k) 
	//{
	//	// not enough nums to put atleast one in each 'k' bucket
	//	if (nums.size() < k)
	//		return false;

	//	// check if it is possible to divide the total sum into k partition (bucket)
	//	int total_sum = std::accumulate(nums.begin(), nums.end(), 0);
	//	if (total_sum % k != 0)
	//		return false;

	//	visited.resize(max_size, false);
	//	return canPartitionKSubsetsHelper(nums, visited, k, 0, 0, total_sum / k);
	//}

	//bool canPartitionKSubsetsHelper(vector<int>& nums, vector<bool>& visited, int k, int start, int currSum, int targetSum)
	//{
	//	cout << k << " " << currSum << endl;
	//	// all 'k' buckets can be filled with the target sum
	//	if (k == 0)
	//		return true;

	//	// if 'k' is filled with the target sum, recurse it for 'k-1' bucket.
	//	if (currSum == targetSum)
	//		return canPartitionKSubsetsHelper(nums, visited, k - 1, start, 0, targetSum);

	//	//invalid configuration
	//	if (currSum > targetSum)
	//		return false;

	//	for (int i = 0; i < nums.size(); i++)
	//	{
	//		visited[i] = true;
	//		if (canPartitionKSubsetsHelper(nums, visited, k, 0, currSum + nums[i], targetSum))
	//			return true;
	//		visited[i] = false;
	//	}
	//	return false;
	//}

	bool canPartitionKSubsetsHelper(vector<int>& nums, vector<int> output, vector<bool>& visited, int k, int start, int currSum, int target)
	{
		if (k == 0)
			return true;

		if (target == currSum)
		{
			all_solution.push_back(output);
			output.clear();
			return canPartitionKSubsetsHelper(nums, output, visited, k - 1, 0, 0, target);
		}
		else if (target < currSum)
			return false;

		for (int i = start; i < nums.size(); i++)
		{
			if (!visited[i] && target >= nums[i])
			{
				visited[i] = true;
				output.push_back(nums[i]);
				if (canPartitionKSubsetsHelper(nums, output, visited, k, i + 1, currSum + nums[i], target))
					return true;
				output.pop_back();
				visited[i] = false;
			}
		}
		return false;
	}

	bool canPartitionKSubsets(vector<int>& nums, int k)
	{
		// check if it is possible to divide the total sum into k partition (bucket)
		int total_sum = std::accumulate(nums.begin(), nums.end(), 0);
		if (total_sum % k != 0)
			return false;

		if (nums.size() < k)
			return false;

		visited.resize(max_size, false);
		vector<int> output;
		return canPartitionKSubsetsHelper(nums, output, visited, k, 0, 0, total_sum / k);
	}
};

int main_K_Partition()
{
	Solution sln;
	vector<int> vec = { 4, 3, 2, 3, 5, 2, 1 };
	cout << sln.canPartitionKSubsets(vec, 4) << endl;
	//sln.subset(vec, 4);
	vector<vector<int>>::const_iterator it = sln.all_solution.begin();
	while (it != sln.all_solution.end())
	{
		for (auto num : *it)
			cout << num << " ";
		cout << endl;
		it++;
	}
	return 0;
}