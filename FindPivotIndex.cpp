// 724. Find Pivot Index
// https://leetcode.com/problems/find-pivot-index/

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define SQ(a) (a)*(a)
#define REP(i,a,b) for (int i = a; i <= b; i++)

class Solution {
public:
    
    //Multiple pass solution
    int pivotIndex2(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> left{nums}, right{nums};
        
        if (n == 1)
            return 0;
        
        for (int i = 1; i<n; i++)
            left[i] += left[i-1];
        
        for (int i = (int)n-1; i>0; i--)
            right[i-1] += right[i];
                
        if (right[1] == 0)
            return 0;
        
        for (int i=1; i<n-1; i++)
            if (left[i-1] == right[i+1])
                return i;
        
        if (left[n-2] == 0)
            return n-1;
        
        return -1;
    }
    
    int pivotIndex(vector<int>& nums) 
    {
        // Initialize rightSum to store the sum of all the numbers strictly to the index's right...
        int rightSum = std::accumulate(nums.begin(), nums.end(), 0);
        
        // Initialize leftSum to store the sum of all the numbers strictly to the index's left...
        int leftSum = 0;
        
        for (int idx = 0; idx<nums.size(); idx++)
        {
            // subtract current elements with from rightSum...
            rightSum -= nums[idx];
            
            // If the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right...
            if (rightSum == leftSum)
                return idx;
            
            // add current elements with leftSum...
            leftSum += nums[idx];
        }
        
        return -1;// If there is no index that satisfies the conditions in the problem statement...
    }
};

int main()
{
    Solution sln;
    vector<int> vec = {1,7,3,6,5,6};
    cout<<sln.pivotIndex(vec)<<endl;
    return 0;
}