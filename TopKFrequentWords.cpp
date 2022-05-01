//https://leetcode.com/problems/top-k-frequent-words/

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

class CustomCompareClass {
public:
	bool operator()(const pis& lhs, const pis& rhs)
	{
		if (lhs.first == rhs.first)
			return lhs.second < rhs.second; // string compare
		return lhs.first > rhs.first; // freq compare
	}
};

class Solution {
	priority_queue<pis, vector<pis>, CustomCompareClass> maxheap;
	unordered_map<string, int> freqCnt;
	vector<string> result;
public:
	vector<string>& topKFrequent(vector<string>& words, int k)
	{
		for (auto& word : words)
			freqCnt[word]++;

		for (auto& item : freqCnt)
		{
			maxheap.push({ item.second, item.first });

			if (maxheap.size() > k)
				maxheap.pop();
		}

		while (!maxheap.empty())
		{
			auto item = maxheap.top();
			result.push_back(item.second);
			maxheap.pop();
		}

		reverse(result.begin(), result.end());
		return result;
	}
	int main()
	{
		vector<string> words = { "i", "love", "leetcode", "i", "love", "coding" };
		Solution sln;
		auto container = sln.topKFrequent(words, 2);
		print(container);
		return 0;
	}
};



