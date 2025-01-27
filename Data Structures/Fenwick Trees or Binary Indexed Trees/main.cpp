#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int bit[N+1] = {0};

/*

i,j
j = remove lat bit of 'i'
i_th bit in bit[N+1] array stores nos(sum) from index `j + 1 -> i`
j = i - (i & -i) // remove last set bit of i  

*/
//FENWICK TREES
struct FenWickTree
{
    vector<int> bit;
    int n ;

    FenWickTree( int n )
    {
        this->n = n;
        bit.assign(n+1,0);
    }

    FenWickTree(vector<int> const &a  ) : FenWickTree(a.size())
    {
        for( int i = 0 ; i < a.size() ; i++ )
        {
            update(i+1,a[i]);
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

    //update simply updates the bit array 
    void update( int i , int x )
    {
        for( ; i <= N ; i += (i & -i) )
        {
            bit[i] += x;
        }
    }

    void print()
    {
        for( auto &it : bit ) cout<<it<<" ";
        cout<<endl;
    }
};




// ( i & -i ) -> return the `rightmost (set)1-bit mask`
// X - (X & -X ) TO REMOVE RIGHTMOST SET BIT

//to get range_sum(l,r) , ans = sum(r_index) - sum(l_index-1)

int main()
{
    vector<int> a = {1,2,3,4,5,6,7,8};
    FenWickTree t(a);
    t.print();


    return 0;

}
