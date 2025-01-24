#include<bits/stdc++.h>
using namespace std;

int extended_gcd(int a, int b , int& x , int& y )
{
    if( b == 0 )
    {
        /* g*1 + 0*y = g ; ax + by = g ; a = g */
        x = 1;
        y = 0;
        return a;
    }

    int x1 , y1;
    int gcd = extended_gcd(b, a%b , x1 , y1);

    x = y1;
    y = x1 - ceil(a/b)*y1;

    return gcd;
}

int main()
{
    
    return 0;
}