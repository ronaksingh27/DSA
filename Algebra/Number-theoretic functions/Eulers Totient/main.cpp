#include<bits/stdc++.h>
using namespace std;
/*

Eulers theorem and Property allows comuting x^n to very big n
Properties :-
1. if p is prime the , phi(p) = p-1
2. if p is prime and k is a positive integer , then phi(p^k) = p^k - p^(k-1)
3. if a and b are coprime , then phi(a*b) = phi(a) * phi(b)
4. if a and b are not coprime , then phi(a*b) = phi(a) * phi(b) * ( d / phi(d) ) where d = gcd(a,b)

n = p^a1*p^a2*p^a3*...*p^an
phi(n) = n*(1-1/p1)*(1-1/p2)*(1-1/p3)*...*(1-1/pn) where p1,p2,p3 .. are prime factors of n 

a^n congruent_to a^(nmodphi(m)) mod m
*/

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

/* O(NloglogN)*/
void phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

/*Divisor Sum Property
summation of phi(d) = n where d is a set all positive divisors of n

*/

int main()
{
    
    return 0;
}