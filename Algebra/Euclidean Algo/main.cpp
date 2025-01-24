/*
LCM(A,B) = A*B / gcd(A,B)
*/

#include<bits/stdc++.h>
using namespace std;

int gcd( int a , int b )
{
    if( b == 0 )
    { 
        cout<<"gcd is "<<a<<endl;
        return a;
    }

    return gcd(b , a%b );
}

int main()
{   
    gcd(55,80);
    
    return 0;
}