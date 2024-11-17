#include<bits/stdc++.h>
using namespace std;


struct FenWickTree
{
    vector<int> bit;
    int n ;

    FenWickTree()
    {
        bit.assign(100000,0);
    }

    //value at index correspons to a nums[i] ka count
    FenWickTree(vector<int> const &a  ) : FenWickTree()
    {
        for( int i = 0 ; i < a.size() ; i++ )
        {
            update(a[i]+10001);
        }
    }

    //sum return sum  from 1 to ith element in array
    int sum( int i )
    {
        int ans = 0;
        for( ; i >= 0 ; i -= ( i & -i ) )
        {
            ans += bit[i];
        }
        return ans;
    }

    int sum( int l, int r )
    {
        return sum(r) - sum(l-1);
    }

    //update simply updates the bit array at index indices chaining with i with value x
    void update( int i )
    {
        for( ; i <= 100000 ; i += (i & -i) )
        {
            bit[i] += 1;
        }
    }

    void print()
    {
        for( auto &it : bit ) cout<<it<<" ";
        cout<<endl;
    }
};



class Solution {
public:
/*
5,2,6,1 -> 2,1,1,0
4,5,6,1,2,4,63 -> 2,3,3,0,0,0,0
141,114,145,353,53,51,5 -> 
-1,0,4242,55,-5,-100 -> 2,2,4,2,1,0
10000000,1111,-1,123456,-8,511151 -> 5,2,1,1,0,0





*/

//FENWICK TREES



    vector<int> countSmaller(vector<int>& nums) {
        FenWickTree t(nums);
        int n = nums.size();

        vector<int> ans;
        for(int i = nums.size()-1 ;  i >= 0 ; i-- )
        {
            ans.insert(ans.begin(),t.sum(i+1,n));
        }

        return ans;



    }
};

int main()
{
    vector<int> nums = {5,2,6,1};
    Solution s ;
    vector<int> ans = s.countSmaller(nums);
    for( auto it : ans ) cout<<it<<" ";

    return 0;
}