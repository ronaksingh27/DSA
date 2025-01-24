#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
       k = 2
       1 1 1 -1 1
    */
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        int sum = 0;
        map<int, int> mpp;  // prefix sum map
        mpp[0] = 1;

        for (int i = 0 ; i < n; i++) {
            
            sum += nums[i];

            if (mpp.find(sum - k) != mpp.end()) {
                ans += mpp[sum-k];
            }
            
            mpp[sum]++;
        }

        return ans;
    }
};


int main()
{
    
    return 0;
}