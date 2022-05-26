class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice =INT_MAX;
        int cost=0;
        for(int j=0;j<prices.size();j++){
            if(minPrice>prices[j]){
                minPrice= prices[j];
            }
          if(prices[j]-minPrice > cost){
             cost = prices[j]-minPrice;
          }
      }
        return cost;
    }
};
