#include<bits/stdc++.h>
using namespace std;

/* In TC = O(s + t) checks the occurences of pattern(s) in text(t)*/
vector<int> rabin_karp(string const& s, string const& t)
{
    const int p = 31;
    const int m = 1e9 + 9;
    int S = s.size() , T = t.size();

    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T+1,0);
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 

    long long hs = 0;
    for( int i = 0 ; i < S ; i++ )
    {
        hs = (hs + ((s[i] - 'a' + 1)*p_pow[i])%m)%m;
    }

    vector<int> occurrences;
    for( int i = 0 ; i + S < T ; i++ )
    {
        long long cur_h = (h[i+S] + m - h[i])%m;
        if( cur_h == (hs*p_pow[i])%m )
        {
            occurrences.push_back(i);
        }
    }

    return occurrences;

}

int main()
{
    
    return 0;
}