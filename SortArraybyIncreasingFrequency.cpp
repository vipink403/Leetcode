//https://leetcode.com/problems/sort-array-by-increasing-frequency/

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
typedef pair<int, string> pis;

typedef pair<int, int> pi;

typedef pair<int, int> pi;

typedef pair<int, int> pi;

typedef pair<int, int> pi;

class ComparatorClass
{
public:
	bool operator()(const pi& lhs, const pi& rhs)
	{
		if (lhs.first == rhs.first)
			return lhs.second > rhs.second; // num compare
		return lhs.first < rhs.first;  // freq compare
	}
};

class Solution {
	vector<int> result;
public:
	vector<int>& frequencySort(vector<int>& nums)
	{
		unordered_map<int, int> freqCnt;
		for (auto item : nums)
			freqCnt[item]++;

		priority_queue<pi, vector<pi>, ComparatorClass> maxheap;

		for (auto num_pair : freqCnt)
			maxheap.push({ num_pair.second, num_pair.first });

		int pos = 0;
		result.resize(nums.size());
		while (!maxheap.empty())
		{
			auto num_pair = maxheap.top();
			for (int i = 0; i < num_pair.first; i++)
				result[pos++] = num_pair.second;
			maxheap.pop();
		}

		reverse(result.begin(), result.end());
		return result;
	}

	int main()
	{
		vector<int> vec = { 2, 3, 1, 3, 2 };
		//Solution sln;
		//print(sln.frequencySort(vec));
		//sort(vec.begin(), vec.end(), ComparatorClass2());
		print(vec);
		return 0;
	}
};