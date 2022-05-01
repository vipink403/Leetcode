#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
	vector<int> arr;
public:
	int findTheWinnerHelper(int k, int index)
	{
		cout << k << " " << index << endl;
		if (arr.size() == 1)
			return arr[0];

		// remove (index + k - 1)th friend
		int indexToRemove = (index + k - 1) % (int)arr.size();
		arr.erase(arr.begin() + indexToRemove);
		return findTheWinnerHelper(k, indexToRemove);
	}

	int findTheWinner(int n, int k) 
	{
		arr.resize(n, 0);
		for (size_t i = 0; i < n; i++)
			arr[i] = i + 1;
		return findTheWinnerHelper(k, 0);
	}
};

int main_JosephusProblem()
{
	Solution sln;
	cout << sln.findTheWinner(6,5) << endl;
	return 0;
}