#include <iostream>
#include <algorithm>
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

// The API isBadVersion is defined for you.
int m_badVersion = 0;
bool isBadVersion(int version)
{
	if (version >= m_badVersion)
		return true;
	return false;
}

class Solution {
public:
	int firstBadVersion(int n)
	{
		int left = 1, right = n, mid;
		while (left < right)
		{
			mid = left + (right - left) / 2;
			cout << left << " " << right << " " << mid << endl;
			if (isBadVersion(mid))
				right = mid;	// 1st half
			else
				left = mid + 1;	// 2nd half
		}
		return left;
	}
};

int main_firstBadVersion()
{
	int n, bad;
	Solution sln;
	cin >> n >> bad;
	m_badVersion = bad;
	cout << sln.firstBadVersion(n) << endl;
	cout << INT_MAX << endl;
	return 0;
}