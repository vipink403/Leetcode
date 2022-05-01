//https://leetcode.com/problems/seat-reservation-manager/

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

typedef pair<int, int> pii;

class SeatManager
{
	set<int> unreservedSeat;
public:
	SeatManager(int n)
	{
		for (int i = 1; i <= n; i++)
			unreservedSeat.insert(i);
	}

	// let the set represents unreserved seats only
	int reserve()
	{
		int topSeat = *unreservedSeat.begin();
		unreservedSeat.erase(unreservedSeat.begin());
		return topSeat;
	}

	// remove the set (make seatnumber reserved by removing it from the set)
	void unreserve(int seatNumber)
	{
		unreservedSeat.insert(seatNumber);
	}

	int main()
	{
		return 0;
	}
};
