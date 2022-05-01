#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

void permuteWithSpace(string input, string output)
{
	if (input.empty())
	{
		cout << output << endl;
		return;
	}

	//output += " ";
	//output += input[0];
	string op1{ output };
	op1 += " ";
	op1 += input[0];

	string op2{ output };
	op2 += input[0];
	input.erase(input.begin());

	// Add Space
	permuteWithSpace(input, op1);

	// Do not add Space
	permuteWithSpace(input, op2);
}

void permuteWithCase(string input, string output)
{
	if (input.empty())
	{
		cout << output << endl;
		return;
	}

	string op1{ output };
	op1 += input[0];

	string op2{ output };
	op2 += tolower(input[0]);

	input.erase(input.begin());

	// Do not change case
	permuteWithCase(input, op1);

	// Change case
	permuteWithCase(input, op2);
}

void permuteWithLetterCase(string input, string output)
{
	if (input.empty())
	{
		cout << output << endl;
		return;
	}

	string op1{ output };
	string op2{ output };

	if (isdigit(input[0]))
	{
		op2 += input[0];
		input.erase(input.begin());
		permuteWithLetterCase(input, op2);
		return;
	}
	else if (islower(input[0]))
	{
		op1 += input[0];
		op2 += toupper(input[0]);
	}
	else if (isupper(input[0]))
	{
		op1 += input[0];
		op2 += tolower(input[0]);
	}

	input.erase(input.begin());

	// Do not change case
	permuteWithLetterCase(input, op1);

	// Change case
	permuteWithLetterCase(input, op2);
}

void balancedParenthesis(int openCnt, int closeCnt, string output)
{
	//cout << output << " " << openCnt << " " << closeCnt << endl;

	// parenthesis can never be balanced if # of ')' is greater than # of '('
	if (openCnt > closeCnt || openCnt < 0 || closeCnt < 0)
		return;

	if (openCnt == 0 && closeCnt == 0)
	{
		cout << output << endl;
		return;
	}

	string op1{ output };
	op1 += '(';

	string op2{ output };
	op2 += ')';

	// include open parenthesis
	balancedParenthesis(openCnt - 1, closeCnt, op1);

	// include close parenthesis
	balancedParenthesis(openCnt, closeCnt - 1, op2);
}

int main_permute()
{
  	//string str = "ABCD";
	//string output = { str[0] };
	//permuteWithSpace(str.substr(1, str.size()), output);

	//string input = "PQR";
	//permuteWithCase(input, "");

	//string input = "A1b2";
	//permuteWithLetterCase(input, "");

	int n = 3;
	balancedParenthesis(n, n, "");
	return 0;
}