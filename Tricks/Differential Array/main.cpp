#include<bits/stdc++.h>
using namespace std;


class DifferentialArray
{
    private:
        vector<int> arr;
        vector<int> diff;

    public:
        DifferentialArray(vector<int>& nums)
        {
            int n = nums.size();
            arr.resize(n, 0);
            for (int i = 0; i < n; i++) {
                arr[i] = nums[i];
            }

            diff.resize(n+1, 0);

            if( n > 1 )
            {
                diff[0] = arr[0];
                for(int i = 1; i < n; i++)
                {
                    diff[i] = arr[i] - arr[i-1];
                }
            }
        }

    
        void query(int l, int r, int val)
        {
            diff[l] += val;
            diff[r+1] -= val;
        }

        vector<int> getArray()
        {
            int n = arr.size();
            arr[0] = diff[0];
            for(int i = 1; i < n; i++)
            {
                arr[i] = arr[i-1] + diff[i];
            }

            /*
            arr  : 1 2 3 4 5
            diff : 1 1 1 1 1 0

            */

            return arr;
        }

};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    DifferentialArray da(nums);
    da.query(0, 2, 5);
    
    return 0;
}