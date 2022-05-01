//https://leetcode.com/problems/numbers-with-same-consecutive-differences/#include <iostream>

#include <iostream>
#include <cmath>
#include <string>
#include <climits>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
	void numsSameConsecDiffHelper2(int n, int diff, string output, vector<int>& result)
	{
		if (n < 0)
			return;
		else if (n == 0)
		{
			if (output[0] != '0')
				result.push_back(atoi(output.c_str()));
			return;
		}

		for (int i = 0; i <= 9; i++)
		{
			if (!output.empty())
			{
				string temp(output);
				int ch = output.back() - '0';

				if (ch + i == diff)
				{
					ch += i;
					temp += to_string(ch);
					numsSameConsecDiffHelper(n - 1, diff, temp, result);
				}
				else if (abs(ch - i == diff))
				{
					ch -= i;
					temp += to_string(ch);
					numsSameConsecDiffHelper(n - 1, diff, temp, result);
				}
			}
			else
			{
				string temp;
				temp += to_string(i);
				numsSameConsecDiffHelper(n - 1, diff, temp, result);
			}
		}
	}

	void numsSameConsecDiffHelper(int n, int diff, string output, vector<int>& result)
	{
		//cout << n << " " << output << endl;
		if (n < 0)
			return;
		else if (n == 0)
		{
			if (output[0] != '0')
				result.push_back(atoi(output.c_str()));
			return;
		}
		int i;
		for (i = 0; i <= 9; i++)
		{
			// We should start with each digit (0-9) at a time
			// then append the required digit to it
			// if input's are like n = 3, diff = 5
			/*
				0->1 Not good (1-0 != diff)
				0->2 Not good (2-0 != diff)
				0->3 Not good (3-0 != diff)
				0->4 Not good (4-0 != diff)
				0->5 good	  (5-0 == diff)
					05->0 good (5-0 == diff)
						050 => answer
					05->1 Not good (6-0 != diff)
					...
					...
					...
				0->6 Not good (6-0 != diff)
				0->7 Not good (7-0 != diff)
				0->8 Not good (8-0 != diff)
				0->9 Not good (9-0 != diff)
				1->0 Not good (1-0 != diff)
				1->1 Not good (1-0 != diff)
				1->2 Not good (2-0 != diff)
				1->3 Not good (3-0 != diff)
				1->4 Not good (4-0 != diff)
				1->5 Not good (5-1 != diff)
				1->6 good	  (6-1 == diff)
					16->0 not good (6-0 != diff)	i.e (last character (6) - new character(0) = 6-0 =6)
					16->1 good (6-1 == diff)
			*/
			if (output.empty())
			{
				string temp;
				temp += to_string(i);
				numsSameConsecDiffHelper(n - 1, diff, temp, result);
			}
			else
			{
				string temp(output);
				int ch = output.back() - '0';
				if (abs(ch - i) == diff)	// take care of the difference while calling recurively
				{
					temp += to_string(i);
					numsSameConsecDiffHelper(n - 1, diff, temp, result);
				}
			}
		}
	}

	vector<int> numsSameConsecDiff(int n, int diff, string output)
	{
		vector<int> ans;
		numsSameConsecDiffHelper(n, diff, output, ans);
		return ans;
	}

	int main()
	{
		int n, diff;
		std::cin >> n >> diff;
		Solution sln;
		auto container = sln.numsSameConsecDiff(n, diff, "");
		for (auto item : container)
			std::cout << item << endl;

		return 0;
	}
};