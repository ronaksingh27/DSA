#include<bits/stdc++.h>
using namespace std;


class DSU{
    vector<int> par,size;

    DSU( int n  )
    {
        par.resize(n);
        iota(par.begin(),par.end(),0);
        size.assign(n,1);
    }

    int doFind(int x )
    {
        if( x != par[x] )
        {
            return par[x] = doFind(x);
        }

        return par[x];
    }

    void doUnion(int x , int y )
    {
        x = doFind(x);
        y = doFind(y);

        if( x != y )
        {
            if( size[x] < size[y] )
            {
                swap(x,y);
            }

            size[x] += size[y];
            par[y] = x;
        }
    }


};

int main()
{

}