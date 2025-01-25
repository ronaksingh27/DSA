#include<bits/stdc++.h>
using namespace std;

//input data
int n;
vector<int> a(n);

//preprocessing
int len = (int)sqrt(n + .0) + 1;
vector<int> b(len,0);
for(int i = 0 ; i < n  ; i++)
{
    b[i/len] += a[i];
}

//querying
for( ;; )
{
    int l,r;
    int sum = 0;

    for( int i = l ; i <= r ; i++ )
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
}





int main()
{
    
    return 0;
}