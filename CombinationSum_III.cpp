//https://leetcode.com/problems/combination-sum-iii/

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

	//void combinationSum3(vector<int>& input, int index, vector<int>& output)
	void combinationSum3(int k, int sum, int index, vector<int>& output)
	{
		if (output.size() == k && sum == 0)
			final_result.push_back(output);

		if (sum < 0)
			return;

		for (int i = index; i < 9; i++)
		{
			output.push_back(i);
			combinationSum3(k, sum - i, i + 1, output);
			output.pop_back();
		}
	}

	//vector<vector<int>> combinationSum3(vector<int> input)
	vector<vector<int>> combinationSum3(int k, int sum)
	{
		vector<int> output;
		combinationSum3(k, sum, 1, output);
		return final_result;
	}
	int main()
	{
		Solution sln;
		vector<int> vec = { 1, 2, 3 };
		//auto containers = sln.combinationSum3(vec);
		auto containers = sln.combinationSum3(9, 45);
		for (auto container : containers)
			print(container);

		return 0;
	}
};
