//https://leetcode.com/problems/subsets-ii/

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
	vector<vector<int>> powerSets;
public:
	template<typename T> void print(T& cont)
	{
		for (auto item : cont)
			cout << item << " ";
		cout << endl;
	}

	// Version 3
	void subsetsWithDup(vector<int>& nums, vector<int>& output, int pos)
	{
		//cout << "subsets Helper() is called\n";
		//print(output);
		powerSets.push_back(output);

		for (int i = pos; i < nums.size(); i++)
		{
			//cout << i << " " << pos << endl;
			if (i > pos && nums.at(i) == nums.at(i - 1))
				continue;

			//choose
			output.push_back(nums[i]);

			//Explore
			subsetsWithDup(nums, output, i + 1);

			//Unchoose
			output.pop_back();
		}
		//cout << "End of subsets Helper()" << endl;
	}

	vector<vector<int>>& subsetsWithDup(vector<int>& nums)
	{
		//cout << "subsets is called - Size of vector " << nums.size() << endl;
		vector<vector<int>> temp;
		powerSets.swap(temp);
		vector<int> output;
		subsetsWithDup(nums, output, 0);
		return powerSets;
	}

	int main()
	{
		/*
		Input: nums = [1,2,2]
		Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
		*/
		vector<int> vec{ 1, 3, 3 };
		Solution sln;
		auto conts = sln.subsetsWithDup(vec);
		for (auto cont : conts)
		{
			for (auto item : cont)
				cout << item << " ";
			cout << endl;
		}
		return 0;
	}
};

