#include<bits/stdc++.h>
using namespace std;




int main()
{

    int t;
    cin>>t;

    while( t-- )
    {
        int a , b;
        cin>>a>>b;

        long long ans = (long long)a * (long long)b;
        int gcd = __gcd(a,b);

        if( gcd == 1 )
        {
            if( a == 1 )
            {
                cout<<ans*ans<<endl;
            }
            else cout<<ans<<endl;
        }
        else if( gcd == a )
        {
            ans = (long long)b * (long long)b / a;
            cout<<ans<<endl;
        }
        else
        {
             cout<<ans/gcd<<endl;
            
        }  
    }
    
    return 0;
}