//Search In Infinite Sorted 0-1 Array
//https://www.codingninjas.com/codestudio/problems/search-in-infinite-sorted-0-1-array_696193
//https://leetcode.com/problems/binary-search/discuss/423162/Binary-Search-101-The-Ultimate-Binary-Search-Handbook

#include <vector>
#include <cmath>
#include <cassert>
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

namespace SearchFirstOne
{
	class Solution
	{
		vector<int> m_list;
	public:
		Solution(vector<int>& nums)
		{
			m_list.resize(nums.size(), 0);
			swap(m_list, nums);
		}

		int get(ll index) {	return m_list.at(index); }

		ll firstOne()
		{
			ll low = 0, high = 1, mid;

			// place the low and high index in a way such that the target is present in between them
			while (get(high) < 1)
			{
				low = high;
				high = max((ll)m_list.size() - 1, 2 * high);
			}

			// Apply Binary search between low and high as usual to get the first '1'
			while (high > low)
			{
				ll mid = low + (high - low) / 2;
				if (mid>0 && get(mid - 1) < get(mid))
					return mid;
				else if (get(mid) == 0)
					low = mid + 1;
				else
					high = mid - 1;
			}
			return low;
		}
	};
}

int main_SearchFirstOne()
{
	vector<int> v = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1 };
	SearchFirstOne::Solution sln(v);
	cout << sln.firstOne() << endl;

	/*for (size_t i = 0; i < v.size(); i++)
	{
		cout << "Ceil of " << v[i] - 1 << " is " << sln.ceilingInSortedArray(v[i] - 1, v) << endl;
	}*/
	return 0;
}