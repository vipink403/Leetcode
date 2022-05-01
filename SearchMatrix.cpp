//https://leetcode.com/problems/search-a-2d-matrix/

#include <vector>
#include <cmath>
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


class Solution {
public:

/*
	A. Treat 2D sorted array as 1D sorted array

	B. To convert (row * col) matrix to 1D array 
		use this formula => matrix[x][y] => a[x * col + y]

	C. 1D array convert to (row * col) matrix 
		use this formula => a[x] => matrix[x / col][x % col];
*/
	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		int rowSize = matrix.size(), colSize = matrix[0].size();
		int low = 0, high = (rowSize * colSize) - 1;

		while ( high - low > 1) // to avoid infinite loop
		{
			int mid = low + (high - low) / 2;
			if (matrix[mid / colSize][mid % colSize] > target)
				high = mid - 1;
			else
				low = mid;
		}
		if (matrix[low / colSize][low % colSize] == target)
			return true;
		if (matrix[high / colSize][high % colSize] == target)
			return true;
		return false;
	}
};

int main()
{
	vector<vector<int>> vii;
	//vii.push_back({ 1, 3, 5, 7 }); 
	//vii.push_back({ 10, 11, 16, 20 });
	//vii.push_back({ 23, 30, 34, 60 });
	vii.push_back({ 1 });
	vii.push_back({ 3 });
	vii.push_back({ 4 });
	vii.push_back({ 5 });

	/*int i = 0;
	int row = vii.size(), col = vii[0].size();
	int low = 0, high = row*col - 1;
	for (size_t i = low; i <= high; i++)
		cout << vii[i / row][i % row] << " " << i / row << " " << i%row << endl;*/
		//cout << vii[i / col][i % col] << "\t" << i / col << "\t" << i % col << endl;

	Solution sln;
	for (size_t i = 0; i < 61; i++)
	{
		bool answer = sln.searchMatrix(vii, i);
		if (answer)
			cout << i << endl;
	}
	return 0;
}