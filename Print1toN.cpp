#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <iterator> 
#include <filesystem>
#include <functional>   // std::not1
#include <algorithm>    // std::count_if
using namespace std;

// Print n to 0
void printReverse(int n)
{
	if (n < 0)
		return;

	cout << n << endl;
	printReverse(n - 1);
}

// Print 1 to n
void print(int n)
{
	if (n < 1)
		return;

	print(n - 1);
	cout << n << endl;
}

int main_print_using_recursion()
{
	printReverse(10);
	return 0;
}