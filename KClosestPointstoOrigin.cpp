//https://leetcode.com/problems/k-closest-points-to-origin

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

template<typename T>
void print(T& container)
{
	for (auto num : container)
	{
		cout << num << "\n";
	}
	cout << endl;
}

typedef pair<int, vector<int>*> pii;
#define sq(x) (x*x) 

class Solution {
	priority_queue<pii> maxheap;
	vector<vector<int>> result;
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
	{
		for (auto& coordinate_pair : points)
		{
			int dist = sq(coordinate_pair[0]) + sq(coordinate_pair[1]);
			maxheap.push({ dist, &coordinate_pair });

			if (maxheap.size() > k)
				maxheap.pop();
		}

		while (!maxheap.empty())
		{
			auto& coordinate_pair = maxheap.top();
			result.push_back(*coordinate_pair.second);
			maxheap.pop();
		}

		return result;
	}

	int main()
	{
		vector<vector<int>> coordinates = { { 3, 3 }, { 5, -1 }, { -2, 4 } };
		Solution sln;
		for (auto container : sln.kClosest(coordinates, 2))
			print(container);
		return 0;
	}
};



