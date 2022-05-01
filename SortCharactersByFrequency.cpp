//https://leetcode.com/problems/sort-characters-by-frequency/

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
typedef pair<int, string> pis;
typedef pair<int, int> pi;
typedef pair<char, int> pci;
#define sq(x) (x*x) 

typedef pair<int, int> pi;
unordered_map<char, int> freqCnt;
class Solution
{
public:
	struct compare
	{
		bool operator()(const char& lhs, const char& rhs)
		{
			int freq_lhs = freqCnt[lhs], freq_rhs = freqCnt[rhs];
			if (freq_lhs == freq_rhs)
				return lhs < rhs;
			return freq_lhs > freq_rhs;
		}
	};

	struct compare2
	{
		bool operator()(const pi& lhs, const pi& rhs)
		{
			if (lhs.first == rhs.first)
				return lhs.second < rhs.second;
			return lhs.first > rhs.first;
		}
	};

	/*
	Time Complexity: O((52 log 52) + Length of the string)  = O (Length of the string) = O(n).
	52 log 52 => constant
	Space Complexity: O(52) or constant
	*/
	string frequencySort(string str)
	{
		freqCnt.clear();
		for (auto ch : str)
			freqCnt[ch]++;

		vector<pi> arr;

		for (auto local_pair : freqCnt)
			arr.push_back({ local_pair.second, local_pair.first });

		sort(arr.begin(), arr.end(), compare2());
		//reverse(arr.begin(), arr.end());

		string result;
		for (auto local_pair : arr)
		{
			for (int i = 0; i < local_pair.first; i++)
				result = string(local_pair.first, (char)local_pair.second) + result;
		}
		return result;
	}
};