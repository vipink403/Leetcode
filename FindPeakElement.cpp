//162. Find Peak Element
//https://leetcode.com/problems/find-peak-element/
//https://leetcode.com/problems/binary-search/discuss/423162/Binary-Search-101-The-Ultimate-Binary-Search-Handbook

#include <vector>
#include <cmath>
#include <random>
#include <cassert>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

template<typename T>
void print(T& container)
{
	for (auto num : container)
	{
		cout << num << "\n";
	}
	cout << endl;
}

namespace FindPeakElement
{
	class Solution {
	public:
		int solve2(const vector<int>& nums)
		{
			int sz = nums.size();
			ll low = 0, high = sz - 1, mid;

			if (sz == 1)
				return 0;
			else if (sz == 2)
				return (nums[low] < nums[high]) ? high : low;
			
			while (high > low )
			{
				ll mid = low + (high - low) / 2;
				cout << mid << " " << low << " " << high << endl;
				if ((mid > 0) && nums[mid - 1] < nums[mid] && (mid<sz - 1) && nums[mid]>nums[mid + 1])
					return mid;
				else if (mid > 0 && nums[mid - 1] > nums[mid])
					high = mid - 1;
				else if ((mid < sz - 1) && nums[mid] < nums[mid + 1])
					low = mid + 1;
			}
			return -1;
		}

		int solve(const vector<int>& nums)
		{
			int sz = nums.size();

			// Only one element
			if (sz == 1) return 0;

			// Check first element
			if (nums[0] > nums[1]) return 0;

			// Check last element
			if (nums[sz - 1] > nums[sz - 2]) return (sz - 1);

			int low = 1, high = sz - 2, mid;
			while (high >= low)
			{
				mid = low + (high - low) / 2;
				if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
					return mid;
				else if (nums[mid - 1] > nums[mid]) // Go the left to find atleast one peak element (since previous item of mid is greater
					high = mid - 1;
				else if (nums[mid + 1] > nums[mid]) // Go the right to find atleast one peak element (since next item of mid is greater
					low = mid + 1;
			}

			return -1;
		}
	};
};

int main_FindPeakElement()
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(1, pow(2, 31) - 1); // distribution in range [1, 6]

	std::ofstream outfile;
	outfile.open("C:\\Users\\vkehri166703\\OneDrive - Applied Materials\\Desktop\\log.txt", std::ios_base::app); // append instead of overwrite

	for (size_t i = 0; i < 1000; i++)
	{
		long long num = dist6(rng);
		outfile << num << ",";
	}

	vector<int> v = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 };
	FindPeakElement::Solution sln;
	cout << sln.solve({ 1, 2, 3, 1 }) << endl;
	//cout << sln.solve({ 1, 2, 1, 3, 5, 6, 4 }) << endl;
	//cout << sln.solve2({ 2, 1 }) << endl;
	return 0;
}
