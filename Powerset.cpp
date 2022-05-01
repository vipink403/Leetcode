#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

void powerSet(string input, string output)
{
	if (input.empty())
	{
		cout << output << endl;
		return;
	}

	char character = input.back();
	input.erase(input.end() - 1);

	// include character in the output
	powerSet(input, output + character);

	// exclude character in the output
	powerSet(input, output);
}

int main_powerSet()
{
	powerSet("ABCD", "");

	/*					
											   input = "abc", output = ""
									exclude	/                          \ include
							input = "", output = "bc"                   input = "a", output = "bc"
					exclude		/               \	include				exclude/                   \ include
              input = "", output = "c"  input = "b", output = "c"  input = "a", output = "c"    input = "a", output = "c"

	*/
	return 0;
}