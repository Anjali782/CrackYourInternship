class Solution {
public:
    int dp[10001][7][7];
    int mod = 1000000007;
    
    int gcd(int a, int b)
    {
    int result = min(a, b); 
      while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
         }
        result--;
       }
       return result; 
    }
    
    int solve(int count , int n , int prev , int secprev){
      if(count==n){
          return 1;
      }
      if(dp[count][prev][secprev]!=-1){
          return dp[count][prev][secprev];
      }
      int ans = 0;  
      for(int i=1;i<=6;i++){
          if(prev == 0 || (i!=prev && i!= secprev && gcd(i , prev)==1)){
              ans  = (ans%mod + solve(count+1,n,i,prev)%mod )%mod; 
          }
      }
        return dp[count][prev][secprev] = ans;
    }
    
    int distinctSequences(int n) {
      memset(dp, -1, sizeof(dp));  
        return solve(0 , n , 0 , 0);
    }
};
