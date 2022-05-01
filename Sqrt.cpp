#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <set>
#include <fstream>
#include <random>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define epsilon 1e-6

template<typename T>
void print(T& container)
{
	for (auto num : container)
	{
		cout << num << "\n";
	}
	cout << endl;
}

class Solution {
public:
	long long mySqrt(long long num)
	{
		if (num == 0 && num == 1)
			return num;

		long long low = 0, high = num;

		//not using equal to to avoid infinite loop
		while (high > low)
		{
			long long mid = high - (high - low) / 2;
			if (mid*mid > num)
			{
				high = mid - 1;
			}
			else
				// can not use "mid-1" because we can not exclude "mid" if (mid*mid = num)
				low = mid;
		}
		//cout << low << " " << high << endl;
		//long long result = round(low);
		return low;
	}
};

int main_mySqrt()
{
	std::ofstream outfile;
	outfile.open("C:\\Users\\vkehri166703\\OneDrive - Applied Materials\\Desktop\\log.txt", std::ios_base::app); // append instead of overwrite

	Solution sln;
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(1, pow(2,31)-1); // distribution in range [1, 6]

	//for (size_t i = 0; i < 100; i++)
	{
		long long num = 1600;// dist6(rng);
		outfile << num << "\t" << sln.mySqrt(num) << "\t" << sqrt(num) << endl;
	}
	return 0;
}
