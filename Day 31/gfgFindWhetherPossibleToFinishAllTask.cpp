bool dfs_cycle(vector<unordered_set<int> >& graph, int node,
               vector<bool>& onpath, vector<bool>& visited)
{
    if (visited[node])
        return false;
    onpath[node] = visited[node] = true;
    for (int neigh : graph[node])
        if (onpath[neigh] || dfs_cycle(graph, neigh, onpath, visited))
            return true;
    return onpath[node] = false;
}
 
// Main function to check whether possible to finish all tasks or not
bool canFinish(int numTasks, vector<pair<int, int> >& prerequisites)
{
    vector<unordered_set<int> > graph = make_graph(numTasks, prerequisites);
    vector<bool> onpath(numTasks, false), visited(numTasks, false);
    for (int i = 0; i < numTasks; i++)
        if (!visited[i] && dfs_cycle(graph, i, onpath, visited))
            return false;
    return true;
}
