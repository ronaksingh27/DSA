#include<bits/stdc++.h>
using namespace std;

long long stringHash(string s)
{
    const int m = 1e9 + 9;
    const int p = 31;

    long long p_pow = 1;
    long long hashVal = 0;

    for(char &c : s )
    {
        hashVal = (hashVal + ((c - 'a' + 1)*p_pow)%m)%m;
        p_pow = (p_pow*p)%m;
    }
    
    return hashVal;

}

int main()
{
    
    return 0;
}