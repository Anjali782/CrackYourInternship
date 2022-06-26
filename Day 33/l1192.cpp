class Solution {
public:
    void dfs(int node , int parent ,vector<int>&vis ,vector<int>&tin , vector<int>&low , int &timer , vector<vector<int>>& g , vector<vector<int>>&ans){
    
        vis[node]=1;
        tin[node] = low[node] = timer++;
        for(auto it:g[node]){
            if(it==parent){
                continue;
            }
            if(!vis[it]){
                dfs(it , node , vis , tin , low , timer , g , ans);
                low[node]=min(low[node] , low[it]);
                if(low[it]>tin[node]){
                    ans.push_back({node , it});
                }
            }
            else{
                low[node]= min(low[node] , tin[it]); 
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
       vector<vector<int>>g(n);
        for(auto &i:connections){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        
      vector<int>tin(n,-1); //to coolect time of insertion of nodes
      vector<int>low(n,-1); // lowest time of insertion
      vector<int> vis(n, 0);
      vector<vector<int>> ans;  
        int timer=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i , -1 , vis , tin , low , timer , g , ans);
            }
        }
        return ans;
    }
};
