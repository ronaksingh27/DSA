#include<bits/stdc++.h>
using namespace std;

/* Trivial algo , TC = O(n^3)*/
vector<int> prefix_function(string& s)
{
    int n = (int)s.size();
    vector<int> pi;
    for( int i = 0 ; i < n ; i++ )
    {
        for(int k = 0 ; k <= i ; i++ )
        {
            if( s.substr(i,k) == s.substr(i-k+1,k))
            {
                pi[i] = k;
            }
        }
    }

    return pi;
}

// Function to compute prefix function π[i]
void computePrefixFunction(string& s, int n, int pi[]) {
    pi[0] = 0;
    int j = 0;//length of longest prefix sum

    for(int i = 1 ; i < n ; i++ )
    {
        while( j > 0 && s[i] != s[j] )
        {
            j = pi[j-1];
        }

        if( s[i] == s[j] )
        {
            j++;
        }

        pi[i] = j;
    }
}

void searchSubstr(string& s, int pi[] , string t )
{
    int i = 0 , j = 0;

    while( i < t.size() )
    {
        if( t[i] == s[j] )
        {
            i++;
            j++;

            if( j == s.size() )
            {
                cout<<"string found at index "<<i-j<<endl;
                j = pi[j-1];
            }
        }
        else
        {
            if (j > 0)
                j = pi[j - 1];
            else
                i++;
        }
    }
}


int main() {
    string pattern = "abc";
    string text = "abcabcabc";

    int pi[pattern.size()];
    computePrefixFunction(pattern, pattern.size(), pi);

    cout << "Prefix Function Array: ";
    for (int x : pi) cout << x << " ";
    cout << endl;

    searchSubstr(pattern, pi, text);

    return 0;
}