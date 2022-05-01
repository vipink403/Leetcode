#include <iostream>
#include <stack>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

// "2[abc]3[cd]ef"

/*
Stack based solution:
Idea is to loop through the string
1. push every character (except ']') in the stack;
2. If current character is ']', we need to solve this subproblem
2i). Fetch the substring "str" inside current '[]' by popping characters from the stack
2ii). if the current character is '[', pop it so that we can fetch the value of k (number of times current substring needs to be appended)
2iii) Fetch the k by poping all the consecutive numbers
2iv) reverse the substring "str"
2v) reverse k;
3. Insert all of the characters of the substring str in the stack. Repeat it for k times.
4. Stack will have the final answer
*/
class Solution {
public:
	stack<char> stk;
	string decodeString(string s) 
	{
		int i = 0;
		while (i < s.size())
		{
			if (s[i] != ']')
				stk.push(s[i]);
			else
			{
				string str, num;
				while (!stk.empty())
				{
					// alphabet
					if (isalpha(stk.top()))
					{
						str += stk.top();
						stk.pop();
					}
					// opening bracket - Just pop
					else if (stk.top() == '[')
						stk.pop();
					// a number
					else if (isdigit(stk.top()))
					{
						num += stk.top();
						stk.pop();
						while (!stk.empty() && isdigit(stk.top()))
						{
							num += stk.top();
							stk.pop();
						}
						break;
					}
				}
				reverse(num.begin(), num.end());
				reverse(str.begin(), str.end());
				string subresult = str;
				for (int i = 0; i < stoi(num); i++)
				{
					for (int j = 0; j < (int)str.size(); j++)
						stk.push(str[j]);
				}
			}
			i++;
		}
		string ans;
		while (!stk.empty())
		{
			ans += stk.top();
			stk.pop();
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

int main_DecodeString()
{
	Solution sln;
	cout << sln.decodeString("3[a]2[bc]") << endl;
	return 0;
}