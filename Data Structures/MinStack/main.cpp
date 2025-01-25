#include<bits/stdc++.h>
using namespace std;


int main()
{
    stack<pair<int,int>> st;

    //add element
    int new_elem = 20;
    int new_min = st.empty() ? new_elem : min(new_elem , st.top().second);
    st.push({new_elem,new_min});

    //remove element
    int removed_element = st.top().first;
    st.pop();

    //get min element
    int min_element = st.top().second;

    return 0;
}