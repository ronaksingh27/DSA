/*
1.Modular Inverse using Extended Euclidean Algorithm

2.Modular Inverse using Binary Expoenetiation and Euler/Fermats Theorem
*/

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

/*1.Modular Inverse using Extended Euclidean Algorithm*/
void inv_extended_euclidean(int a , int m)
{
    int x , y;
    int g = extended_gcd(a,m,x,y);
    if( g != 1 )
    {
        cout << "Inverse does not exist" << endl;
    }
    else
    {
        x = (x % m + m) % m;
        cout << "Modular Inverse : " << x << endl;
    }
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

/* O(n^1/2)*/
int phi(int n)
{
    int result = n;
    for( int i = 2 ; i*i <= n ; i++ )
    {
        if( n % i == 0 )
        {
            while( n % i == 0 )
            {
                n /= i;
            }
            result -= result / i;
        }
    }

    if( n > 1 )
    {
        result -= result / n;
    }

    return result;
}


/*1.Modular Inverse using Extended Euclidean Algorithm*/
void inv_binary_expo(int a , int m)
{
    int p = phi(m);
    int x = binpowrec(a,p-1);
    cout << "Modular Inverse : " << x << endl;
}

int main()
{
    
    return 0;
}