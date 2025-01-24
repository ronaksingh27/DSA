#include<bits/stdc++.h>
using namespace std;

long long binpow( long long a, long long b)
{
    long long res = 1;
    /*
        res = 1
        3^1010 = 3^8 * 3^2
    */
    while( b > 0 )
    {
        if( b & 1 )
        {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }

    return res;
}


/*
a*b*c*d modm = (a modm * b modm * c modm * d modm) modm
*/
long long binpowmod( long long a , long long b )
{
    long long res = 1;
    long long mod = 1e9 + 7;

    a = a % mod; 
    while( b > 0  )
    {
        if( b & 1 ) res = (res * a) % mod;
        a = (a * a) % mod;
        b >= 1;
    }

    return res;
}

long long binpowrec( long long a , long long b )
{
    if( b == 0 ) return 1;

    long long res = binpowrec(a,b/2);

    if( b & 1 )
    {
        return res * res * a;
    }
    else{
        return res * res;
    }
}

/*
also you could use fermats theorem

x^n = x^(n mod (m-1)) mod m for prime m

*/



int main()
{
    
    return 0;
}