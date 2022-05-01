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
};

int mainHeapIntro()
{
	priority_queue<int> maxheap;
	maxheap.push(1);
	maxheap.push(5);
	maxheap.push(2);
	maxheap.push(10);

	priority_queue<int, vector<int>, greater<int> > minHeap;
	minHeap.push(1);
	minHeap.push(5);
	minHeap.push(2);
	minHeap.push(10);
	while (!minHeap.empty())
	{
		cout << minHeap.top() << endl;
		minHeap.pop();
	}
	return 0;
}

