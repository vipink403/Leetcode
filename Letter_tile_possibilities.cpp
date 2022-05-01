//https://leetcode.com/problems/letter-tile-possibilities/

#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <climits>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std; 

class Solution {
public:
	set<string> allPossibilities;
	void numTilePossibilitiesHelper(string tiles, string output)
	{
		if (tiles.empty())
		{
			allPossibilities.insert(output);
			return;
		}

		for (size_t i = 0; i < tiles.size(); i++)
		{
			// choose
			char ch = tiles[i];
			output += ch;

			allPossibilities.insert(output);
			tiles.erase(tiles.begin() + i);

			// Explore
			numTilePossibilitiesHelper(tiles, output);

			// Unchoose
			tiles.insert(tiles.begin() + i, ch);
			output.erase(output.end() - 1);
		}
	}

	int numTilePossibilities(string tiles) 
	{
		numTilePossibilitiesHelper(tiles, "");
		return allPossibilities.size();
	}
	int main()
	{
		string str = "AAB";
		Solution sln;
		cout << sln.numTilePossibilities(str) << endl;
		for (auto item : sln.allPossibilities)
			cout << item << endl;
	
		cout << "End of the program" << endl;
		return 0;
	}
};
