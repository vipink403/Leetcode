//https://leetcode.com/problems/permutations/

#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <climits>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<int>> allPermutations;
	void permute(vector<int>& nums, vector<int> output)
	{
		if (nums.empty())
		{
			allPermutations.push_back(output);
			return;
		}

		for (size_t i = 0; i < nums.size(); i++)
		{
			// choose
			int item = nums[i];
			output.push_back(item);
			nums.erase(nums.begin() + i);

			//Explore
			permute(nums, output);

			//unchoose
			output.pop_back();
			nums.insert(nums.begin() + i, item);
		}
	}

	vector<vector<int>> permute(vector<int>& nums)
	{
		vector<int> output;
		permute(nums, output);
		return allPermutations;
	}

	int main()
	{
		vector<int> items{ 1, 2, 3 };
		/*
		Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
		*/
		Solution sln;
		auto containers = sln.permute(items);
		for (auto container : containers)
		{
			for (auto num : container)
				cout << num << " ";
			cout << endl;
		}
		return 0;
	}
};
