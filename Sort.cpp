#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

namespace sort_an_array
{
	void insert(vector<int>& arr, int val)
	{
		// two cases for arr[0...n-1
		//1. The last item i.e arr[n-1]<=val, append the val item
		//2. The last item i.e arr[n-1]>val, process the arr first i.e sort it by inserting the val at the right place

		cout << "val = " << val << endl;

		// Base
		if (arr.empty() || arr.at(arr.size() - 1) < val)
		{
			arr.push_back(val);
			return;
		}

		// Hypothesis (process the last item)
		// take the last element out and try to place it at the right position
		int last_item = arr[arr.size() - 1];
		arr.pop_back();
		cout << "last_item = " << last_item << endl;

		// Induction (process the remaining "n-1" items)
		insert(arr, last_item);
		arr.push_back(last_item);
	}

	void sortv(vector<int>& arr)
	{
		// Base
		if (arr.empty())
			return;

		// Hypothesis (process the last item)
		// take the last element out and try to place it at the right position
		int val = arr[arr.size() - 1];
		arr.pop_back();
		sortv(arr);

		// Induction (process the remaining "n-1" items)
		insert(arr, val);
	}
}

namespace sort_a_stack
{
	static void insert(deque<int>& arr, int val)
	{
		// Base
		if (arr.empty() || arr.back() <= val)
		{
			arr.push_back(val);
			return;
		}

		// Hypothesis
		int last_item = arr.back();
		arr.pop_back();
		insert(arr, val);

		// Induction
		arr.push_back(last_item);
	}

	static void sort(deque<int>& arr)
	{
		// Base
		if (arr.empty())
			return;

		// Hypothesis
		int last_item = arr.back();
		arr.pop_back();
		sort(arr);

		// Induction
		insert(arr, last_item);
	}
}

int main_sort()
{
	deque<int> vec = { 5, 19, 93, 88, 21, 71, 42 };
	sort_a_stack::sort(vec);

	for (auto item : vec)
		cout << item << " ";
	cout << endl;
	return 0;
}