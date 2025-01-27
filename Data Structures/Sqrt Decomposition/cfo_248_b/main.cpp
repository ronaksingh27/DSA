#include<bits/stdc++.h>
using namespace std;


void calPfSum(vector<int64_t>&pfSum,vector<int64_t> a )
{
    sort(a.begin(),a.end());
    if( a.size() > 0 ) pfSum[0] = a[0];
    for( int64_t i = 1 ; i < a.size() ; i++ )
    {
        pfSum[i] += pfSum[i-1] + a[i];
    }
}

void calRange(vector<int64_t>& a,vector<int64_t>& b,int64_t l,int64_t r )
{
    int64_t len = b.size();
    int64_t sum = 0;
    for( int64_t i = l ; i <= r ;  )
    {
        if( i % len == 0 && i + len -1 <= r  )//complete block used in query
        {
            sum += b[i/len];
            i += len;
        }
        else
        {
            sum += a[i];
            i++;
        }
    }

    cout<<sum<<endl;
}


void preprocessSqrtDecomp(vector<int64_t>&b,vector<int64_t>& a )
{
    //preprocessing
    int64_t n = a.size();
    int64_t len = (int64_t)sqrt(n + .0) + 1;
    b.resize(len,0);
    for(int64_t i = 0 ; i < n  ; i++)
    {
        b[i/len] += a[i];
    }
}

int32_t main()
{
    int64_t n;
    cin>>n;

    vector<int64_t> a(n);
    for( auto &it : a ) cin>>it;

    vector<int64_t>pfSum(n,0);
    calPfSum(pfSum,a);

    vector<int64_t> b;
    preprocessSqrtDecomp(b,a);

    int64_t m;
    cin>>m;
    while( m-- )
    {
        int64_t t,l,r;
        cin>>t>>l>>r;

        if( t == 2 )
        {
            cout<<pfSum[r-1] - (l-2 >= 0 ? pfSum[l-2] : 0)<<endl;
        }
        else
        {
            if( l-1 >= 0 && l <= r ) calRange(a,b,l-1,r-1);
            else calRange(a,b,0,r-1);
        }


    }
    return 0;
}