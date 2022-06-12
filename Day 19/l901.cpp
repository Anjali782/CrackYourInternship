class StockSpanner {
public:
    stack<pair<int , int>>stk;
    StockSpanner() {
      while(!stk.empty()){
          stk.pop();
      }  
    }
    
    int next(int price) {
     if(stk.empty() || price<stk.top().first){
         stk.push({price , 1});
         return 1;
     }
     else{
      int count=1;
      while(!stk.empty() && price>=stk.top().first){
          count += stk.top().second;
          stk.pop();
      }
        stk.push({price , count});
        return count;
     }   
    }
};
