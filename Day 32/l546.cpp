class Solution {
public:
    int dp[101][101][101];
    vector<int> grp;  //contains the length of each consecutive sequence
    vector<int> val;   // contains the value of each consecutive sequence

    int calc(int l,int r,int extras)
    {
        if(l>r)return 0;
    
        if(dp[l][r][extras]!=-1)
            return dp[l][r][extras];
        
        int take= (grp[l]+extras)*(grp[l]+extras) + calc(l+1,r,0);
        int not_take=0;
        
        for(int j=l+1;j<r;j++)
        {
            if(j+1<=r && val[j+1]==val[l])  // merge current grp to a next grp only if their values are equal
            not_take=max(not_take,calc(l+1,j,0)+calc(j+1,r,extras+grp[l]));  
        }
        return dp[l][r][extras]=max(take,not_take);
    }
    int removeBoxes(vector<int>& bx) {
        
        int cnt=1;
        memset(dp,-1,sizeof(dp));
        
        for(int i=1;i<bx.size();i++)
        {
            if(bx[i]==bx[i-1])
                cnt++;
            else
            {
                grp.push_back(cnt);
                val.push_back(bx[i-1]);
                cnt=1;
            }
        }
        grp.push_back(cnt);
        val.push_back(bx[bx.size()-1]);
 
        return calc(0,grp.size()-1,0);
        
    }
};
