//https://leetcode.com/problems/sort-colors/

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define SQ(a) (a)*(a)
#define REP(i,a,b) for (int i = a; i <= b; i++)

void sortColors(vector<int>& nums) 
{
    int freq[3];
    memset(freq, 0, sizeof(freq));

    for (auto& item : nums)
        freq[item]++;

    int index = 0, cnt = 0;
    while (index < nums.size())
    {
    	cout<<index<<" "<<cnt<<endl;
        while(cnt < 3 && freq[cnt]--)
            nums[index++] = cnt;
        cnt++;
    }
    for(auto item : nums)
        cout<<item<<" ";
}

int main()
{
    vector<int> vec = {2,0,2,1,1,0};
    sortColors(vec);
    return 0;
}