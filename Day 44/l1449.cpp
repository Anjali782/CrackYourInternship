class Solution {
public:
    string sol(vector<int>& cost , int target , unordered_map<int , string> &dp){
      if(target<0){
          return "0";
      } 
      if(target==0){
          return "";
      } 
      if(dp.find(target)!=dp.end()){
          return dp[target];
      } 
      string cur,res = "0";
      for(int i=0;i<9;i++){
          cur = sol(cost , target-cost[i] , dp);
          if(cur == "0"){
              continue;
          }
          cur = to_string(i+1)+cur;
          if(cur.size() >= res.size()){
              res=cur;
          }
      }
        dp[target] = res;
        return res;
    }
    string largestNumber(vector<int>&cost, int target) {
     unordered_map<int , string>dp;
       return sol(cost , target , dp);
    }
};
