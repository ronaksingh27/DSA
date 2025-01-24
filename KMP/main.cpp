#include<bits/stdc++.h>
using namespace std;


void computeLPS(string& pattern,vector<int>& lps )
{   
    int i = 1 , length = 0;
    lps[0] = 0;

    /*
        a b c d a b c e f g 
        0 0 0 0 1 2 3 0 


        a b c d a b c e a b c g h
        0 0 0 0 1 2 3 0 1 2 3 
    
    */
    while( i < pattern.size() )
    {
        if( pattern[i] == pattern[length] )
        {
            length++;
            lps[i] = length;
            i++;
        }
        else
        {
            if( length == 0 )
            {
                lps[i] = 0;
                i++;
            }
            else if( length != 0 )
            {
                length = lps[length-1];
            }
        }

    }

}

void KMPSearch(string& text , string& pattern)
{
    int i = 0 , j = 0;
    int n = text.size() ,m = pattern.size();

    vector<int> lps(m,0);
    
    computeLPS(pattern,lps);

    while( i < n )
    {
        
        if( text[i] == pattern[j] )
        {
            i++;
            j++;
        }

        if( j == m )
        {
            cout<<"String pattern found at index "<<i-j<<endl;
            j = lps[j-1];
        }
        else if( i < n && pattern[j] != text[i] )
        {
            if( j != 0 )
            {
                j = lps[j-1];
            }
            else
            {
                i++;
            }
        }




    }
}


int main() {
    string text = "ababcabcabababdababd";
    string pattern = "ababd";
    
    KMPSearch(text, pattern);
    
    return 0;
}