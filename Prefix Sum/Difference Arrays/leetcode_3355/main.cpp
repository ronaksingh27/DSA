#include<bits/stdc++.h>
using namespace std;

/*  https://www.youtube.com/watch?v=R-PBfqsRGP0&ab_channel=Techdose */
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> relHt(n, 0);

        relHt[0] = nums[0];
        for (int i = 1; i < n; i++) {
            relHt[i] = nums[i] - nums[i - 1];
        }


        for( auto& it : queries )
        {
            int l = it[0] , r = it[1];
            relHt[l] -= 1;
            if(r + 1 < n ) relHt[r+1] += 1;
        }

        //final nums
        nums[0] = relHt[0];
        for( int i = 1 ; i < n  ; i++ )
        {
            nums[i] = nums[i-1] + relHt[i];
        }

        for( auto& it : nums )  if( it > 0 ) return false;

  

        return true;
    }
};