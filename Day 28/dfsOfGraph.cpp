class Solution{  
public:
    void dfs(int v , vector<int>&vis , vector<int> adj[] , vector<int>&store){
        store.push_back(v);
        vis[v]=1;
        for(auto i:adj[v]){
            if(!vis[i]){
                dfs(i , vis,adj , store);
            }
        }
    }
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        vector<int>vis(v , 0);
        vector<int>store;
        if(!vis[0]){
            dfs(0 , vis , adj , store);
        }
        return store;
    }
};
