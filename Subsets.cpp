//https://leetcode.com/problems/subsets/

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
	vector<vector<int>> powerSets;
public:
	void subsets(vector<int> nums, vector<int>& output)
	{
		if (nums.empty())
		{
			powerSets.push_back(output);
			return;
		}

		vector<int> output1(output);
		vector<int> output2(output);

		output2.push_back(nums.back());

		// Make input smaller
		nums.erase(nums.end() - 1);

		// take the current item (i.e nums.back()) and recurse
		subsets(nums, output2);

		// Do not take current item (i.e nums.back()) and recurse
		subsets(nums, output1);
	}

	vector<vector<int>> subsets_recursion(vector<int>& nums)
	{
		vector<int> output;
		subsets(nums, output);
		return powerSets;
	}

	vector<vector<int>> subsets_iterative(vector<int>& nums)// [1 2 3]
	{
		powerSets.clear();

		// First insert empty subset
		powerSets.push_back(vector<int>());

		// Loop through each num
		for (int num : nums) // [1 2 3]
		{
			// create a new subset by Copying each subset from the powerSet one by one and add current num to each subset and pushback the newly created subset
			/* powerSet = { {}, {1}}
			num = 2;
			temp = {} // copy powerSet[0]
			temp = {2} // insert num. It is a new subset. Add it to the result
			powerSet = { {}, {1}, {2}
			temp = {1} // copy powerSet[1]
			temp = {1,2} // insert num. It is a new subset. Add it to the result
			powerSet = { {}, {1}, {2}, {1,2} }

			num = 3
			temp = {} // copy powerSet[0]
			temp = {3} // insert num. It is a new subset. Add it to the result
			powerSet = { {}, {1}, {2}, {1,2} , {3} }
			temp = {1} // copy powerSet[1]
			temp = {1, 3} // insert num. It is a new subset. Add it to the result
			powerSet = { {}, {1}, {2}, {1,2} , {3}, {1,3} }
			similarly do for the powerSet[2] and powetSet[3]
			*/
			int subsets_so_far_cnt = powerSets.size();
			for (int i = 0; i < subsets_so_far_cnt; i++)
			{
				vector<int> temp(powerSets[i]);
				temp.push_back(num);
				powerSets.push_back(temp);
			}
		}
		return powerSets;
	}

	// Version 3
	void subsets(vector<int>& nums, vector<int>& output, int pos)
	{
		//cout << pos << endl;
		powerSets.push_back(output);

		for (size_t i = pos; i < nums.size(); i++)
		{
			//choose
			output.push_back(nums[i]);

			//Explore
			subsets(nums, output, i + 1);

			//Unchoose
			output.pop_back();
		}
	}

	vector<vector<int>>& subsets(vector<int>& nums)
	{
		powerSets.clear();
		vector<int> output;
		subsets(nums, output, 0);
		return powerSets;
	}

	int main()
	{
		vector<int> vec = { 1, 2, 3 };
		Solution sln;
		//auto conts1 = sln.subsets(vec);
		//for (auto cont : conts1)
		//{
		//	for (auto item : cont)
		//		cout << item << " ";
		//	cout << endl;
		//}

		auto conts2 = sln.subsets(vec);
		for (auto cont : conts2)
		{
			for (auto item : cont)
				cout << item << " ";
			cout << endl;
		}
		return 0;
	}
};



