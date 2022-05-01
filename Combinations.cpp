//https://leetcode.com/problems/combinations/
//https://www.youtube.com/watch?v=fqrOsZdKegQ&list=PLzffTJx5aHaSJ4XaG55cI3Z0VrNOyLWpH&index=2&t=185s

#include <iostream>
#include <string>
#include <vector>
#include <deque>
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
	Logic is same as Subset / Powerset generation
	Just that we need to insert the combination of length 'k' in the final list
	*/
	void generateCombination(int num, int k, vector<int>& output)
	{
		if (output.size() == k)
		{
			final_result.push_back(output);
			return;
		}

		for (int i = num; i>0; i--)
		{
			output.push_back(i);
			generateCombination(i - 1, k, output);
			output.pop_back();
		}
	}

	vector<vector<int>>& combine(int n, int k)
	{
		vector<int> output;
		generateCombination(n, k, output);
		return final_result;
	}

	int main()
	{
		Solution sln;
		auto containers = sln.combine(4, 2);
		for (auto container : containers)
			print(container);

		return 0;
	}
};

