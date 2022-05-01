//Floor in a Sorted Array
//https://www.geeksforgeeks.org/floor-in-a-sorted-array/
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

namespace FloorSearch
{
	class Solution
	{
	public:
		/*Given a sorted array and the target value, the floor of target value is the largest element in array smaller than or equal to target value.*/
		int floorSearch(const vector<int>& nums, int target)
		{
			int result = INT_MIN;
			int low = 0, high = nums.size() - 1;
			while (high - low > 1) // to avoid infinite loop by ensuring that the two items are left for processing
			{
				int mid = low + (high - low) / 2;
				//cout << low << " " << high << " " << mid << endl;
				if (nums[mid] > target)  // exclude mid
				{
					high = mid - 1;
				} 
				else // include mid
				{
					result = max(result, mid);
					low = mid;
				}
			}

			// Now, only two items are remaining to process / compare
			if (nums[low] <= target)
				result = max( low, result);
			if (nums[high] <= target)
				result = max(high, result);
			return (result == INT_MIN ? -1 : result);
		}
	};
}

int main_FloorSearch()
{
	FloorSearch::Solution sln;
	vector<int> v = { 1, 2, 4, 6, 10, 12, 14 };
	cout << "Floor of " << 4 << " is " << sln.floorSearch({ 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113 }, 159) << endl;
	/*for (size_t i = 0; i < v.size(); i++)
		cout << "Floor of "<<v[i]<<" is "<< sln.floorSearch({ 3,4 }, v[i]) << endl;*/
	return 0;
}