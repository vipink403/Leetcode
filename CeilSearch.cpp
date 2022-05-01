//Ceil in a Sorted Array
//https://www.codingninjas.com/codestudio/problems/ceiling-in-a-sorted-array_1825401
//https://leetcode.com/problems/binary-search/discuss/423162/Binary-Search-101-The-Ultimate-Binary-Search-Handbook

#include <vector>
#include <cmath>
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
Given an unsorted array Arr[] of N integers and an integer X, find floor and ceiling of X in Arr[0..N-1].

Floor of X is the largest element which is smaller than or equal to X. Floor of X doesn’t exist if X is smaller than smallest element of Arr[].

Ceil of X is the smallest element which is greater than or equal to X. Ceil of X doesn’t exist if X is greater than greatest element of Arr[].

Return -1 if floor or ceil is not present.
*/

namespace CeilSearch
{
	class Solution
	{
	public:
		int ceilingInSortedArray(int target, const vector<int> &nums)
		{
			int low = 0, high = nums.size() - 1, result = INT_MAX;
			while (high - low > 1)
			{
				int mid = low + (high - low) / 2;
				if (nums[mid] < target)
					low = mid + 1;
				else
				{
					result = min(result, nums[mid]);
					high = mid;
				}
			}

			if (nums[low] >= target)
				result = min(result, nums[low]);
			if (nums[high] >= target)
				result = min(result, nums[high]);
			return (result == INT_MAX ? -1 : result);
		}
	};
}

int main_CeilSearch()
{
	CeilSearch::Solution sln;
	vector<int> v = { 1, 1, 3, 4, 4, 5 };
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << "Ceil of " << v[i]-1 << " is " << sln.ceilingInSortedArray(v[i]-1, v) << endl;
	}
	return 0;
}

