#include<bits/stdc++.h>
using namespace std;


int f( vector<int>& a )
{
    int n = a.size();
    int l = 0 , r = n-1 , mid;

    while( l <= r )
    {
        mid = l + (r-l)/2;
        int num = mid + 1;

        printf("l = %d , r = %d , mid = %d\n",l,r,mid);
        printf("num = %d , a[%d] = %d\n",num,mid,a[mid]);

        if( num == a[mid] )
        {
            l = mid + 1;
        }
        else if( num != a[mid] ) {
            r = mid - 1;
        }

    }

    printf("ans = %d\n",mid+1);


    return mid+1;

}



int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 8, 9};

    return f(a);


}