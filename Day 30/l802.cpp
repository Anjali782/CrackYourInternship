class Solution {
public:
    bool dfs(vector<vector<int>>& graph , int node , vector<bool>&vis , vector<bool>&dfsVis , vector<bool>&pre_cycle){
        vis[node]=1;
        dfsVis[node]=1;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(dfs(graph , it , vis , dfsVis , pre_cycle)){
                    return pre_cycle[node]= true;
                }
            }
            else if(vis[it] && dfsVis[it]){
               return pre_cycle[node]= true;
            }
        }
        dfsVis[node]=0;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
         int n= graph.size();
        vector<bool>pre_cycle(n , false);
        vector<int>ans;
        
        vector<bool>vis(n, false);
        vector<bool>dfsVis(n ,false);
        
        //we will find those nodes who are not  involved in making cycle
        for(int i=0;i<n;i++){
           if(!vis[i]){
              dfs(graph , i , vis , dfsVis , pre_cycle);
           }
        }
        for(int i=0;i<n ;i++){
            if(!pre_cycle[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
