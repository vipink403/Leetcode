//https://leetcode.com/problems/combination-sum-ii/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
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
	vector<vector<int>> final_result;
public:
	/*
	Subset with Duplicate input
	*/
	void knapsack(vector<int>& candidates, int target, vector<int>& output, int index)
	{
		if (target == 0)
		{
			final_result.push_back(output);
			return;
		}

		if (target < 0)
			return;

		for (int i = index; i < candidates.size(); i++)
		{
			if (i > index && candidates[i] == candidates[i - 1])
				continue;
			output.push_back(candidates[i]);
			knapsack(candidates, target - candidates[i], output, i + 1);
			output.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
	{
		vector<int> output;
		sort(candidates.begin(), candidates.end());
		knapsack(candidates, target, output, 0);
		return final_result;
	}

	int main()
	{
		Solution sln;
		vector<int> vec = { 10, 1, 2, 7, 6, 1, 5 };
		auto containers = sln.combinationSum2(vec, 8);
		for (auto container : containers)
			print(container);

		return 0;
	}
};


