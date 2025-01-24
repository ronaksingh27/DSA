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
int mod_inv(int a , int m)
{
    int x , y;
    int g = extended_gcd(a,m,x,y);
    if( g != 1 )
    {
        cout << "Inverse does not exist" << endl;
        return -1;
    }
    else
    {
        x = (x % m + m) % m;
        return x;
    }
}

struct Congruence
{
    int a;
    int m;
};

long long CRT(vector<Congruence> congruences )
{
    long long M = 1;
    for( auto const& c : congruences)
    {
        M *= c.m;
    }

    long long solution = 0;
    for( auto const& c : congruences)
    {
        long long Mi = M /c.m;
        long long xi = mod_inv(Mi,c.m);
        solution += (c.a * Mi * xi)%M;
    }

    return solution % M;

}


int main()
{
    // Test Case 1: Example with two congruences
    vector<Congruence> congruences1 = {
        {2, 3},  // x ≡ 2 (mod 3)
        {3, 5}   // x ≡ 3 (mod 5)
    };
    cout << "Test Case 1 Result: " << CRT(congruences1) << endl; // Expected: 8

    // Test Case 2: Example with three congruences
    vector<Congruence> congruences2 = {
        {1, 3},  // x ≡ 1 (mod 3)
        {4, 5},  // x ≡ 4 (mod 5)
        {6, 7}   // x ≡ 6 (mod 7)
    };
    cout << "Test Case 2 Result: " << CRT(congruences2) << endl; // Expected: 34

    // Test Case 3: Larger moduli
    vector<Congruence> congruences3 = {
        {3, 7},   // x ≡ 3 (mod 7)
        {5, 13},  // x ≡ 5 (mod 13)
        {7, 17}   // x ≡ 7 (mod 17)
    };
    cout << "Test Case 3 Result: " << CRT(congruences3) << endl; // Expected: 205

    // Test Case 4: Single congruence (simplest case)
    vector<Congruence> congruences4 = {
        {4, 9}    // x ≡ 4 (mod 9)
    };
    cout << "Test Case 4 Result: " << CRT(congruences4) << endl; // Expected: 4

    // Test Case 5: Moduli are not coprime (expected to fail or give incorrect result)
    vector<Congruence> congruences5 = {
        {2, 4},   // x ≡ 2 (mod 4)
        {3, 6}    // x ≡ 3 (mod 6)
    };
    cout << "Test Case 5 Result: " << CRT(congruences5) << endl; // Behavior undefined (moduli are not coprime)

    return 0;
}
