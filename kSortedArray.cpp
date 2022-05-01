
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

// Sort nearly sorted array
class Solution 
{
public:
	void nearly_sort(vector<int>& nums, int k)
	{
		//priority_queue<int, vector<int>, greater<int>> minheap
		//make_heap(nums.begin(), nums.begin() + k);

		priority_queue<int, vector<int>, greater<int>> minheap{nums.begin(), nums.begin() + k};
		
		int pos = 0;

		// Heap size should be equal to k
		for (int i = k; i < nums.size(); i++)
		{
			// insert the (pos)th smallest element at the pos location
			nums[pos++] = minheap.top();

			// remove the (pos)th smallest element
			minheap.pop();

			// Push the next num
			minheap.push(nums[i]);
		}

		// insert the remamining num from heap to the desired position
		while (!minheap.empty())
		{
			nums[pos++] = minheap.top();
			minheap.pop();
		}
	}

	int main()
	{
		Solution sln;
		vector<int> vec = { 6, 5, 3, 2, 8, 10, 9 };
		sln.nearly_sort(vec, 3);
		print(vec);
		return 0;
	}
};



