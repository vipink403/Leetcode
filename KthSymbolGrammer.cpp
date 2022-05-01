//https://leetcode.com/problems/k-th-symbol-in-grammar
//https://www.youtube.com/watch?v=5P84A0YCo_Y&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=10

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std; 

class SolutionKthGrammer {
public:

	/*
	N = 1; [0]
	N = 2; [01]
	N = 3; [0110]
	N = 4; [01101001]
	N = 5; [0110100110010110]
	index   [123456789]
	Let's take any adjacent row (or say N = 3 and 4).


	N = 3; [0110]
	N = 4; [01101001]
	index:     [12345678]

	The points to be noted:-
	+ The first half of nth row (N=4) is exactly same as the (n-1)th (N=3)row
	+ The remaining 2nd half of the nth row is exactly opposite of the (n-1)th row

	to solve the problem of (n,k), we need to figure out the next smaller value of k.

	solve(n,k)
	/        \
	solve(n-1,k)   solve(n-1,k-mid) [either of these two call not both]
	And the call to subproblem depends on the value of k. Whether it is greater than the max size of the
	nth row.

	*/
	int kthGrammar(int n, long long k)
	{
		if (n == 1 && k == 1)
			return 0;

		int mid = pow(2, n - 1) / 2;
		if (k <= mid)
			return kthGrammar(n - 1, k);
		else
			return !(kthGrammar(n - 1, k - mid));
	}
};