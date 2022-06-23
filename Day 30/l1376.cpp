class Solution {
public:
    vector<int>adj[100005];
    int dfs(int headid , vector<int>&informTime){
        int maxi=0;
        for(auto it: adj[headid]){
            maxi = max(maxi , dfs(it , informTime));
        }
        return informTime[headid]+maxi;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
      for(int i=0;i<manager.size();i++){
          if(manager[i]!=-1){
              adj[manager[i]].push_back(i);
          }
      }
        return dfs(headID , informTime);
    }
};
