class Solution
{
    public:
    int solve(int n, int x, int y, int z)
    {
        vector<int>dp(n+1,INT_MIN);
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            if(i-x >=0)
            dp[i]=max(dp[i],dp[i-x]+1);
            if(i-y>=0)
            dp[i]=max(dp[i],dp[i-y]+1);
            if(i-z>=0)
            dp[i]=max(dp[i],dp[i-z]+1);
        }
        return dp[n]<0?0:dp[n];
    }
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        return solve(n,x,y,z);
    }
};
