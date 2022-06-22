class Solution{
 public:
   bool dfs(int i ,int par , vector<int>&vis , vector<int>adj[]){
       vis[i]=1;
       for(auto p : adj[i]){
           if(!vis[p]){
               if(dfs(p ,i, vis , adj))
               {return true;}
           }else{
               if(p!=par){
                   return true;
               }
           }
       }
       return false;
   }
    bool isCycle(int v, vector<int> adj[]) {
        vector<int>vis(v , 0);
        for(int i=0;i<v;i++){
        if(!vis[i]){
            if(dfs(i ,-1, vis , adj) == 1){
                return true;
            }
        }
      }
        return false;
    }
};
