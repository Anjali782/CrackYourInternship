#include <bits/stdc++.h>
#include<cstring>
using namespace std;

class Solution {
public:
    string sol(vector<int>&cost , int target ,vector<string>&dp){
     if(target<0){
          return "0";
      } 
      if(target==0){
          return "";
      } 
      if(dp[target]!=""){
          return dp[target];
      } 
      string cur,res = "0";
      for(int i=25;i>=0;i--){
          cur = sol(cost , target-cost[i] , dp);
          if(cur == "0"){
              continue;
          }
          cur = static_cast<char>(i+97) + cur;
          if(cur > res){
              res=cur;
          }
      }
        dp[target] = res;
        return res;
    }
    string largestNumber(vector<int>&cost, int target) {
     vector<string>dp(target+1 , "");
     string ans="";
       return sol(cost , target , dp );
    }
};

int main()
{
    Solution s;
    vector<int>cost={252,888,578,746,295,884,198,665,503,868,942,506,718,498,727,338,43,768,783,312,369,712,230,106,102,554};
    int target = 6674;
    cout<<s.largestNumber(cost , target);
    return 0;
}
