#include<bits/stdc++.h>
using namespace std;


class DSU{
    public:
    vector<int> par,size;
    int connected_components;


    DSU( int n  )
    {
        par.resize(n);
        iota(par.begin(),par.end(),0);
        size.assign(n,1);
        connected_components = n;
    }

    int doFind(int x )
    {
        if( x != par[x] )
        {
            return par[x] = doFind(par[x]);
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
            connected_components--;
        }
    }


};

int main()
{
    int n;
    cin>>n;

    DSU dsu(n);
    for( int i = 0 ; i < n-1 ; i++ )
    {
        int x,y;
        cin>>x>>y;
        dsu.doUnion(x,y);
    }

    cout<<"connected components : "<<dsu.connected_components<<endl;
}