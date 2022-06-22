class Solution {
public:
    void dfs( unordered_map<int , vector<int>>&adj , int node , vector<bool>&vis){
        vis[node]=1;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(adj , it , vis);
            }
        }
    }
        
    int makeConnected(int n, vector<vector<int>>& connections) {
     vector<bool>vis(n , false);
     unordered_map<int , vector<int>>adj;
      int edges=0;
        //make adjacency list
      for(int i=0;i<connections.size();i++){
          adj[connections[i][0]].push_back(connections[i][1]);
          adj[connections[i][1]].push_back(connections[i][0]);
          edges += 1;
      } 
       //finf no. of componants
        int comp=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                comp += 1;
                dfs(adj , i , vis);
            }
        }
      // count edges
        if(edges<n-1){
            return -1;
        }
        int red = edges-((n-1)-(comp-1));
        if(red >= (comp-1)){
            return comp-1;
        }
        return -1;
    }
};
