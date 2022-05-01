//https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

#define sz 21

class Solution {
	vector<string> grammer;
public:

	Solution() { createBinaryString(); }

	void createBinaryString()
	{
		grammer.resize(sz);

		grammer[0] = "0";

		for (int i = 1; i<sz; i++)
		{
			string temp = grammer[i] = grammer[i - 1];
			invert_and_reverse(temp);
			grammer[i] += "1";
			grammer[i] += temp;
		}

		/*for (auto str : grammer)
			cout << str << " ";
		cout << endl;*/
	}

	void invert_and_reverse(string& arr)
	{
		for (int i = 0; i<arr.size(); i++)
		{
			if (arr[i] == '0')
				arr[i] = '1';
			else
				arr[i] = '0';
		}

		reverse(arr.begin(), arr.end());
	}

	char findKthBit(int n, int k)
	{
		createBinaryString();
		string str = grammer.at(n - 1);
		cout << str[k-1] << endl;
		return 0;//grammer[n-1].at(k-1);
	}
};

int main_kBithNthBinaryString()
{
	Solution sln;
	cout << sln.findKthBit(3, 4) << endl;
	return 0;
}