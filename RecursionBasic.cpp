#include <iostream>
#include <stack>
#include <string>
#include <climits>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define sz 2001
#define max_sz 1001

void printDiceRoll(int n, string out = "")
{
	if (n == 0)
	{
		cout << out << endl;
		return;
	}

	for (size_t i = 1; i <= 6; i++)
	{
		string temp(out);
		temp += to_string(i);
		printDiceRoll(n - 1, temp);
	}
}

void printDecimal(int n, string out = "")
{
	if (n == 0)
	{
		cout << out << endl;
		return;
	}

	for (size_t i = 0; i <= 9; i++)
	{
		// Create the outputs by appending the required character to the existing output 
		string temp(out);
		temp += to_string(i);

		// Recurse with smaller input and newly created outputs
		printDecimal(n - 1, temp);
	}
}

void printBinary(int n, string out = "")
{
	if (n == 0)
	{
		cout << out << endl;
		return;
	}

	// Create the outputs by appending the required character to the existing output 
	string out1(out);
	string out2(out);
	out1 += '0';
	out2 += '1';

	// Recurse with smaller input and newly created outputs
	printBinary(n - 1, out1);
	printBinary(n - 1, out2);
}

//void printBinary(int n)
//{
//	printBinary(n, "");
//}

int main_basic_recursion()
{
	int n;
	cin >> n;
	//printBinary(n, "");
	//printDecimal(n, "");
	printDiceRoll(n, "");
	return 0;
}