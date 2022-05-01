//https://leetcode.com/problems/find-k-closest-elements/

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
public:
	vector<int> findClosestElements(vector<int>& nums, int k, int x)
	{
		priority_queue<pair<int, int> > maxheap;

		for (int i = 0; i < nums.size(); i++)
		{
			maxheap.push(make_pair(abs(nums[i] - x) , nums[i]));

			if (maxheap.size() > k)
				maxheap.pop();
		}

		vector<int> result;
		while (!maxheap.empty())
		{
			result.push_back(maxheap.top().second);
			maxheap.pop();
		}
		sort(result.begin(), result.end());
		return result;
	}

	int main()
	{
		Solution sln;
		vector<int> vec = { 1, 2, 3, 4, 5, 21, 21, 22, 53, 64, 73, 78, 87, 184, 238, 246, 267, 323, 358, 432, 546, 548, 564, 732, 747, 769, 787, 987 };
		print(sln.findClosestElements(vec, 4, 3));
		return 0;
	}
};



