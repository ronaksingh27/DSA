#include<bits/stdc++.h>
using namespace std;
/*

task : day , gym or contest 
0 - nothing
1 - contest
2 - sport
3 -> both
 */
int f( int day, int prev_task ,vector<int>& v )
{
    if( day == v.size() ) return 0;

    
    int restDays = INT_MAX;
    int notRestDay = INT_MAX;

    int a = v[day];

    if( a == 0 )
    {
        restDays = 1 + f(day+1,0,v);
    }
    else if( a == 1 )
    {
        if( prev_task != 1 )
        {
            restDays = 1 + min(f(day+1,1,v),f(day+1,0,v));
        }
            
    }
    else if( a == 2 )
    {
        if( prev_task != 2 )
        {
            restDays = 1 + min(f(day+1,2,v),f(day+1,0,v));
        }
    }
    else
    {
        if( prev_task != 1 )
        {
            restDays = 1 + min(f(day+1,1,v),f(day+1,0,v));
        }
        else if( prev_task != 2 )
        {
            restDays = 1 + min(f(day+1,2,v),f(day+1,0,v));
        }

        
    }


    

    int result  = min(take,notTake);
 
    return result;
}

int main()
{
    
    int n;
    cin>>n;
    vector<int> v(n);
    for( auto &it : v ) cin>>it;

    // int n = 4;
    // vector<int> v = {1,3,2,0};
    
    cout<<f(0,-1,v);
    return 0;
}