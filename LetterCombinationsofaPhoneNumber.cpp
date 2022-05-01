//https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <iostream>
#include <string>
#include <vector>
#include <set>
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

class Solution {
	unordered_map<int, string> dict;
public:
	Solution()
	{
		dict.insert(make_pair(2, "abc"));
		dict.insert(make_pair(3, "def"));
		dict.insert(make_pair(4, "ghi"));
		dict.insert(make_pair(5, "jkl"));
		dict.insert(make_pair(6, "mno"));
		dict.insert(make_pair(7, "pqrs"));
		dict.insert(make_pair(8, "tuv"));
		dict.insert(make_pair(9, "wxyx"));
	}

	vector<string> letterCombinations(string digits) 
	{
		return vector<string>();
	}
};

int main2a()
{
	Solution sln;
	auto container = sln.letterCombinations("23");
	print(container);
	return 0;
}

