class Solution {
public:
    int N,M;
    vector<vector<int>>dp;
    
    int dfs(int x , int y, vector<vector<int>>&matrix){
        if(dp[x][y]){
            return dp[x][y];
        }
        vector<vector<int>>dir = {{-1,0},{1,0},{0,1},{0,-1}};
        int ans=1;
        for(int i=0;i<4;i++){
            int xx=x+dir[i][0];
            int yy=y+dir[i][1];
            if(xx<0 || yy>=M || xx>=N || yy<0){
                continue;
            }
            if(matrix[x][y]>=matrix[xx][yy]){
               continue;
            }
            ans = max(ans , 1+dfs(xx , yy , matrix));
        }
        return dp[x][y]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
      int n=matrix.size();
       if(n==0){
         return 0;
       }
      int m= matrix[0].size();
        N=n;
        M=m;
        dp=vector<vector<int>>(n , vector<int>(m , 0));
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res = max(res , dfs(i , j , matrix));
            }
        }
       return res; 
    }
};
