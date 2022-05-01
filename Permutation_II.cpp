//https://leetcode.com/problems/permutations-ii/

#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <climits>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

/*
https://leetcode.com/problems/permutations-ii/discuss/18628/Accepted-backtracking-C%2B%2B-solution-by-using-map-(28ms)

 I see most solutions are using next permutation. That's great and only uses O(1) space.

Anyway I am sharing backtracking solution which uses O(n) space. This is actually a typical backtracking problem. We can use hash map to check whether the element was already taken. However, we could get TLE if we check vector num every time. So we iterate the hash map instead.
*/
class Solution {
public:
	vector<vector<int>> allUniquePermutations;
	map<int, int> hash;

	void permuteUnique(vector<int>& nums, vector<int>& output)
	{
		if (nums.size() == output.size())
		{
			allUniquePermutations.push_back(output);
			return;
		}

		for (auto& local_pair : hash)
		{
			if (local_pair.second <= 0)
				continue;

			// choose
			local_pair.second--;
			output.push_back(local_pair.first);

			//Explore
			permuteUnique(nums, output);

			//unchoose
			local_pair.second++;
			output.pop_back();
		}
	}

	vector<vector<int>> permuteUnique(vector<int>& nums)
	{
		for (size_t i = 0; i < nums.size(); i++)
		{
			hash.insert(std::make_pair(nums[i], 0));
			hash[nums[i]]++;
		}

		vector<int> output;
		permuteUnique(nums, output);
		return allUniquePermutations;
	}
	int main()
	{
		vector<int> items{ 1, 1, 2 };
		/*
		Output:
		[[1,1,2],
		[1,2,1],
		[2,1,1]]
		*/
		Solution sln;
		auto containers = sln.permuteUnique(items);
		for (auto container : containers)
		{
			for (auto num : container)
				cout << num << " ";
			cout << endl;
		}
		return 0;
	}
};

