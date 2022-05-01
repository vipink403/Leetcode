#include <iostream>
#include <string>
#include <vector>
//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <set>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
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

namespace findMinRotatedSortedArray
{
	class Solution {
	public:
		int findMin(const vector<int>& nums)
		{
			int low = 0, high = nums.size() - 1, mid;
			while (low < high)	// to avoid infinite loop
			{
				mid = low + (high - low) / 2;
				/*if (mid > 0 && nums[mid] < nums[mid - 1])
					return nums[mid];*/
				if (nums[mid] > nums[high])
					low = mid + 1;	// 2nd half
				else
					// 1st half
					high = mid; // "mid" could be the answer, cannot exclude it
			}
			cout << low << " " << high << endl;
			return nums[low];
		}
	};

	int main_findMin()
	{
		vector<int> vec;// = { 4, 5, 6, 7, 0, 1, 2 };
		Solution sln;
		//cout << sln.findMin(vec) << endl;
		cout << sln.findMin({ 1, 2, 3, 4, 5, 6, 7, 0 }) << endl;
		//cout << sln.findMin({ 0, 1, 2, 3, 4, 5, 6, 7 }) << endl;
		//cout << sln.findMin({ 2, 3, 4, 5, 6, 7, 0, 1 }) << endl;
		//cout << sln.findMin({ 3, 4, 5, 6, 7, 0, 1, 2 }) << endl;
		//cout << sln.findMin({ 4, 5, 6, 7, 0, 1, 2, 3 }) << endl;
		//cout << sln.findMin({ 5, 6, 7, 0, 1, 2, 3, 4 }) << endl;
		//cout << sln.findMin({ 6, 7, 0, 1, 2, 3, 4, 5 }) << endl;
		//cout << sln.findMin({ 7, 0, 1, 2, 3, 4, 5, 6 }) << endl;
		return 0;
	}
}