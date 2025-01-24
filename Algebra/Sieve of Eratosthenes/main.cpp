#include<bits/stdc++.h>
using namespace std;

int n;
vector<bool> is_prime(n+1, true);
is_prime[0] = is_prime[1] = false;

/* A number is prime, if none of the smaller prime numbers divides it.*/
for (int i = 2; i <= n; i++) {
    if (is_prime[i] && (long long)i * i <= n) {
        for (int j = i * i; j <= n; j += i)
            is_prime[j] = false;
    }
}

int main()
{
    
    return 0;
}