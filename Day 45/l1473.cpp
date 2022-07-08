class Solution {
public:
    
    int dp[101][21][101];
    
    int solve(int houseNo,int usedColor,int neighour,vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target){
        if(neighour > target){
            return INT_MAX/2;
        }
        if(houseNo == m){
            if(neighour == target){
                return 0;
            }
            return INT_MAX/2;
        }
        if(dp[houseNo][usedColor][neighour]!=-1){
            return dp[houseNo][usedColor][neighour];
        }
        else{
            int ans= INT_MAX/2;
            if(houses[houseNo]==0){
                for(int j=1;j<=n;j++){
                 ans  = min(ans , cost[houseNo][j-1]+solve(houseNo+1,j,(usedColor ==j)?neighour:neighour+1,houses,cost,m,n,target)) ;  
                }
            }
            else{
                 ans  = min(ans ,solve(houseNo+1,houses[houseNo],(usedColor ==houses[houseNo])?neighour:neighour+1,houses,cost,m,n,target));
            }
            return dp[houseNo][usedColor][neighour] = ans ;
        }
        
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
     // dp of house no. , till that index no. which color we are using ,no. of neighours 
     memset(dp , -1 , sizeof(dp));   
     int usedColor=0;
     int houseNo=0;
     int neighour=0;
     int ans = solve(houseNo,usedColor,neighour,houses,cost,m,n,target);
        return ans == INT_MAX/2 ? -1 : ans;
    }
};
