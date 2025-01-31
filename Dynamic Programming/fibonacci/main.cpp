#include<bits/stdc++.h>
using namespace std;

const int MAX_SAVE = 3;
int fib[MAX_SAVE];

int f( int  n )
{
    fib[0] = 0 , fib[1] = 1;

    for( int i = 2 ; i <= n ; i++ )
    {
        fib[ i % MAX_SAVE ] = fib[ (i - 1) % MAX_SAVE ] + fib[ (i - 2) % MAX_SAVE ];
    }

    return fib[n % MAX_SAVE];
}

int main()
{
    
    return 0;
}