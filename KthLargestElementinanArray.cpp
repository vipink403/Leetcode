//https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef pair<int, pair<int, int>> pii;

template<typename T>
void print(T& container)
{
	for (auto num : container)
	{
		cout << num << "\n";
	}
	cout << endl;
}

class Solution {
	priority_queue<int, vector<int>, greater<int>> minheap;
public:
	int findKthLargest1(vector<int>& nums, int k) 
	{
		for (int i = 0; i < nums.size(); i++)
		{
			minheap.push(nums[i]);

			if (minheap.size() > k)
				minheap.pop();
		}

		return minheap.top();
	}

	int findKthLargest2(vector<int>& nums, int k)
	{
		nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), less<int>());

		for (size_t i = 0; i < nums.size(); i++)
			cout << nums.at(i) << " ";
		cout << endl;

		return nums[k-1];
	}

	int findKthLargest(vector<int>& nums, int k)
	{
		partial_sort(nums.begin(), nums.begin() + k, nums.end());
		for (size_t i = 0; i < nums.size(); i++)
			cout << nums.at(i) << " ";
		return nums[k - 1];
	}

	int main()
	{
		Solution sln;
		vector<int> vec = { 3, 2, 1, 5, 6, 4 };
		cout <<"\t" << sln.findKthLargest(vec, 4) << endl;
		return 0;
	}
};


