#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
        1. Count the number of odd numbers from the left. If the count equals k, increment the answer.
    */
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pfOddSum(n, 0);

        // Initialize the prefix sum for the first element
        pfOddSum[0] = (nums[0] & 1);

        // Compute prefix sum of odd numbers
        for (int i = 1; i < n; i++) {
            pfOddSum[i] = pfOddSum[i - 1] + (nums[i] & 1);
        }

        map<int, int> mpp;
        mpp[0] = 1;  // Initialize the map with the base case
        int sum = 0, ans = 0;

        // Iterate through the prefix sum array and update the answer
        for (int num : pfOddSum) {
            if (mpp.find(num - k) != mpp.end()) {
                ans += mpp[num - k];
            }

            mpp[num]++;
        }

        return ans;
    }
};


int main()
{

}