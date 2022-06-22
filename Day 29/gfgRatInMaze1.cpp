class Solution{
    public:
    
    void solve(int i , int j , vector<vector<int>>&matrix , int n , vector<string>&ans , string move , vector<vector<int>>&vis){
        if(i==n-1 && j==n-1){
            ans.push_back(move);
        }
        if(i+1<n && !vis[i+1][j] && matrix[i+1][j]==1){
            vis[i][j]=1;
            solve(i+1,j,matrix,n,ans,move+'D',vis);
            //while returning make it unvisited
            vis[i][j]=0;
        }
        if(j-1>=0 && !vis[i][j-1] && matrix[i][j-1]==1){
            vis[i][j]=1;
            solve(i,j-1,matrix,n,ans,move+'L',vis);
            //while returning make it unvisited
            vis[i][j]=0;
        }
        if(j+1<n && !vis[i][j+1] && matrix[i][j+1]==1){
            vis[i][j]=1;
            solve(i,j+1,matrix,n,ans,move+'R',vis);
            //while returning make it unvisited
            vis[i][j]=0;
        }
        if(i-1>=0 && !vis[i-1][j] && matrix[i-1][j]==1){
            vis[i][j]=1;
            solve(i-1,j,matrix,n,ans,move+'U',vis);
            //while returning make it unvisited
            vis[i][j]=0;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>ans;
        vector<vector<int>>vis(n,vector<int>(n,0));
        if(m[0][0]==1){
            solve(0,0,m,n,ans,"",vis);
        }
        return ans;
    }
};
