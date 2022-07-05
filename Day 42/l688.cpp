class Solution {
public:
    vector<pair<int, int>> jumps= {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    
    double solve(vector<vector<vector<double>>> &dp, int n, int k, int i, int j) {
        if (k==0){
            return 1;   
        } 
        if(i<0 || j<0 || i>=n || j>=n){
            return 0;   
        }  
        if (dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        
        double ans = 0;
        for(auto [dx, dy] : jumps){
            int x=i+dx, y=j+dy;
            if (x>=0 && x<n && y>=0 && y<n){
                ans += 0.125*solve(dp, n, k-1, x, y); 
            }     
        }
        
        return dp[i][j][k] = ans;
    }
    
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n+1, vector<vector<double>>(n+1, vector<double>(k+1, -1)));
        return solve(dp, n, k, row, column); 
    }
};
