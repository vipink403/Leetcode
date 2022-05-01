#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
using namespace std;

//void deleteMiddleElement(deque<int> &stk, int index)
//{
//}

class Solution {
	set<int> dict;
public:
	Solution() {}

	bool containsDuplicate(vector<int>& nums)
	{
		for (auto num : nums)
		{
			if (dict.find(num) != dict.end())
				return false;

			dict.insert(num);
		}
		return true;
	}
};

int main_deleteMiddleElem()
{
	//deque<int> dq = { 1, 2, 3, 4, 5 };
	//int mid = (dq.size() / 2) + 1;
	//deleteMiddleElement(dq, mid);

	Solution sln;
	vector<int> vec = { 1, 2, 3, 1 };
	cout << sln.containsDuplicate(vec) << endl;
	return 0;
}