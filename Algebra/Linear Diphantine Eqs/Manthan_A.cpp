#include <bits/stdc++.h>
using namespace std;

int extended_gcd(int a, int b, int& x, int& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

void find_any_solution(int a, int b, int c)
{

    int x0, y0;
    int g = extended_gcd(abs(a), abs(b), x0, y0);

    if (c % g)
    {
        printf("No");
        return;
    }

    x0 *= c / g;
    y0 *= c / g;

    if (x0 >= 0 && y0 >= 0)
    {
        printf("Yes\n");
    }
    else if (x0 < 0)
    {
        int k = ceil((double)(abs(x0) * g) / b);

        if ( (k > 0) && (y0 - k * (a / g) < 0) )
        {
            printf("No\n");
            return;
        }
        // printf("k = %d\n", k);
        printf("Yes\n");
    }
    else if (y0 < 0)
    {
        int k = ceil((double)(abs(y0) * g) / a);

        if ( (k > 0) && (x0 - k * (b / g) < 0) )
        {
            printf("No\n");
            return;
        }
        // printf("k = %d\n", k);
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    // printf("[DEBUG] Solution: x0 = %d, y0 = %d\n", x0, y0);
    return;
}

int main()
{
    int a, b, c;
    // printf("Enter values for a, b, and c: ");
    cin >> a >> b >> c;

    find_any_solution(a, b, c);

    return 0;
}
