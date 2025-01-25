#include<bits/stdc++.h>
using namespace std;

int add( int idx );
int remove( int idx );
int get_answer();

int block_size;

struct Query{
    int l,r,idx;
    bool operator < (Query other) const
    {
        return make_pair(l/block_size,r) < make_pair(other.l/block_size,other.r);
    }
};

/* Time Complexity : O( (N+Q)sq_root(N) )*/
vector<int> mo_s_algorithm(vector<Query> queries)
{
    vector<int> answers(queries.size());
    int cur_l = 0 , cur_r = -1;
    for( Query q : queries )
    {
        while(  cur_l > q.l )
        {
            cur_l--;
            add(cur_l);
        }
        while( cur_r < q.r )
        {
            cur_r++;
            add(cur_r);

        }
        while( cur_l < q.l )
        {
            remove(cur_l);
            cur_l++;
        }
        while( cur_r > q.r )
        {
            remove(cur_r);
            cur_r--;
        }

        answers[q.idx] = get_answer();
    }

    return answers;
}


int main()
{

    vector<Query> queries;
    
    
    return 0;
}