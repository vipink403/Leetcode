//https://leetcode.com/problems/search-in-rotated-sorted-array/

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

namespace SearchinRotatedSortedArray
{
	class Solution {
	public:
		int bsearch(const vector<int>& nums, int left, int right, int target)
		{
			while (left < right)
			{
				int	mid = left + (right - left) / 2;
				if (nums[mid] < target)
					left = mid + 1;
				else
					right = mid;
			}
			if (nums[left] == target)
				return left;
			else if (nums[right] == target)
				return right;
			return -1;
		}

		int findMin(const vector<int>& nums)
		{
			int left = 0, right = nums.size() - 1, mid;
			while (left < right)
			{
				mid = left + (right - left) / 2;
				if (nums[mid] > nums[right])
					left = mid + 1;	// 2nd half
				else
					right = mid;	// 1st half
			}
			return left;
		}

		int search(const vector<int>& nums, int target)
		{
			int minIndex = findMin(nums);
			if (!minIndex)
			{
				int result = bsearch(nums, 0, nums.size() - 1, target);
				if (result != -1)
					return result;
			}
			else
			{
				int result1 = bsearch(nums, 0, minIndex - 1, target);
				int result2 = bsearch(nums, minIndex, nums.size() - 1, target);
				if (result1 != -1)
					return result1;
				else if (result2 != -1)
					return result2;
			}
			return -1;
		}
	};
}

int main_SearchinRotatedSortedArray()
{
	SearchinRotatedSortedArray::Solution sln;
	cout << sln.search({ 4, 5, 6, 7, 8, 0, 1, 2 }, 0) << endl;
	return 0;
}