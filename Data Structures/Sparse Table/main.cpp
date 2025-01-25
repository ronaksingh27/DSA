#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;
const int LOG = 17;
int a[MAX_N];
int m[MAX_N][LOG];

void preprocess_min_query(int n)
{
    //preprocessing for min_query_O(N*logN)
    for( int k = 1 ; k < LOG ; k++ )
    {
        for(int i = 0 ; i + (1<<k) - 1 < n ; i++ )
        {
            m[i][k] = min(m[i][k-1],m[i+(1<<(k-1))][k-1]);
        }
    }
}

void preprocess_sum_query(int n)
{
    //preprocessing for min_query_O(N*logN)
    for( int k = 1 ; k < LOG ; k++ )
    {
        for(int i = 0 ; i + (1<<k) - 1 < n ; i++ )
        {
            m[i][k] = m[i][k-1]+m[i+(1<<(k-1))][k-1];
        }
    }
}


//range sum query
//time is O(logN) , N -> length of the range
int range_sum_query(int l , int r )
{
    int len = r - l + 1;
    int K = log2(len);

    int sum = 0;
    for(int i = K ; i >= 0 ; i-- )
    {
        if( (1<<i) <= len )
        {
            sum += m[l][i];
            l += (1<<i);
            len -= (1<<i);
        }
    }

    return sum;
}


//range minimum queries
//time is O(1)
int range_min_query(int l, int r )
{
    int len = r - l + 1;
    int k = 0;
    while( (1 << (k+1)) <= len )
    {
        k++;
    }

    return min(m[l][k],m[r-(1<<k)+1][k]);
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    // Input array
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[i][0] = a[i];
    }

    

    

    int q;
    cout << "Enter the number of queries: ";
    cin >> q;

    cout << "Enter the queries in the format: type l r (type: 1 for sum, 2 for min):\n";
    for (int i = 0; i < q; i++) {
        int type, l, r;
        cin >> type >> l >> r;

        if (type == 1) {
            // Range sum query
            // Preprocessing for range sum query
            preprocess_sum_query(n);
            cout << "Range Sum Query (" << l << ", " << r << "): " << range_sum_query(l, r) << endl;
        } else if (type == 2) {
            // Range min query
            // Preprocessing for range minimum query
            preprocess_min_query(n);
            cout << "Range Min Query (" << l << ", " << r << "): " << range_min_query(l, r) << endl;
        } else {
            cout << "Invalid query type!" << endl;
        }
    }

    return 0;
}
