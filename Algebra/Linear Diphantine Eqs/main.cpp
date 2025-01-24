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
    y = x1 - (a/b)*y1;

    return gcd;
}


bool find_any_solution(int a, int b , int c , int& x0 , int& y0 , int & g )
{
    g = extended_gcd(abs(a),abs(b),x0,y0);

    /* if c is divisible by g , we get a solution else a solution does not exist */
    if( c % g )
    {
        return false;
    }

    x0 *= c/g;
    y0 *= c/g;

    if( a < 0 ) x0 = -x0;
    if( b < 0 ) y0 = -y0;

    return true;

}


int main() {
    vector<tuple<int, int, int>> test_cases = {
        {15, 10, 5},
        {-15, 10, 5},
        {-15, -10, 5},
        {7, 4, 10}, 
        {0, 5, 10}, 
        {5, 0, 15} ,{14 ,19, 143} 
    };

    for (int i = 0; i < test_cases.size(); i++) {
        int a, b, c;
        tie(a, b, c) = test_cases[i];
        int x0, y0, g;

        cout << "Test Case " << i + 1 << ": a = " << a << ", b = " << b << ", c = " << c << endl;

        if (find_any_solution(a, b, c, x0, y0, g)) {
            cout << "Solution exists: True" << endl;
            cout << "x = " << x0 << ", y = " << y0 << ", gcd = " << g << endl;
        } else {
            cout << "Solution exists: False" << endl;
        }

        cout << "-----------------------------" << endl;
    }

    return 0;
}