bool isCyclicUtil(int v,vector<int>adj[], bool vis[], bool dfsVis[])
{
    if(visited[v] == false)
    {
        vis[v] = true;
        dfsVis[v] = true;
        
        for(auto it:adj[v])
        {
            if ( !vis[it] && isCyclicUtil(it, adj ,vis, dfsVis) )
                return true;
            else if( dfsVis[it])
                return true;
        }
  
    }
    dfsVis[v] = false;
    return false;
}
bool isCyclic()
{
    bool vis[v];
    bool dfsVis[v];
    for(int i = 0; i < v; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
    for(int i = 0; i < V; i++)
        if ( !vis[i] && isCyclicUtil(i, vis, dfsVis))
            return true;
  
    return false;
}
