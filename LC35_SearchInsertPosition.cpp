//https://leetcode.com/problems/search-insert-position/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template<typename T>
void print(T& container)
{
	for (auto num : container)
	{
		cout << num << "\n";
	}
	cout << endl;
}

/*
  Given a sorted array of distinct integers and a target value, return the index if the target is found. 
  If not, return the index where it would be if it were inserted in order.
  You must write an algorithm with O(log n) runtime complexity.
*/
namespace searchInsertPosition
{
	class Solution {
	public:
		int searchInsert(const vector<int>& nums, int target)
		{
			auto itr = lower_bound(nums.begin(), nums.end(), target);
			return std::distance(itr, nums.begin());
		}
	};
}

int mainsearchInsertPosition()
{
	searchInsertPosition::Solution sln;
	//cout << sln.searchInsert({ 1, 3, 5, 6 }, 2) << endl;
	//cout << sln.searchInsert({ 1, 3, 5, 6 }, 5) << endl;
	//cout << sln.searchInsert({ 1, 3, 5, 6 }, 7) << endl;
	double x = 0.0290;
	cout << abs(x) << endl;
	cout << fabs(x) << endl;
	if (abs(x) > 0)
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}