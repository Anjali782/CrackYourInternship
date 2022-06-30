class Solution {
public:
    vector<vector<vector<int>>>dp;
    int solve(vector<string>& strs, int m, int n , int index){
        if(index==strs.size()){
            return 0;
        }
        if(dp[m][n][index]!=-1){
            return dp[m][n][index];
        }
        int countZero = count(strs[index].begin() , strs[index].end() , '0');
        int countOne= strs[index].size()-countZero;
        if(m-countZero>=0 && n-countOne>=0){
        return dp[m][n][index]=max(1+solve(strs,m-countZero,n-countOne, index+1),solve(strs,m,n,index+1));
        }
        
        return dp[m][n][index]=solve(strs,m,n,index+1);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
     dp.resize(m+1, vector<vector<int>>(n+1 , vector<int>(strs.size() , -1)));
        return solve(strs,m, n , 0);
    }
};
