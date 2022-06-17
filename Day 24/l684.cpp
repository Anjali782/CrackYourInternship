class Solution {
public:
    int Root(int x,vector<int> &parent )
{
    if(parent[x] == -1)
        return x;
   return Root( parent[x],parent);
}

vector<int> findRedundantConnection(vector<vector<int>>& edges) 
{
   int n = edges.size();
    vector<int> parent(n+1,-1);

    for( auto x:edges)
    {
        if( Root(x[0],parent) == Root( x[1],parent) )
            return x;
        
        int t = Root(x[0],parent);
        parent[t] = Root(x[1],parent);
    }
    return {-1};
}
};

