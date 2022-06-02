class Solution {
public:
    bool isHappy(int n) {
       int rem=0;
        int rem1;
        unordered_set<int> s;
        
     while(n!=1){
       if(s.find(n) == s.end())
          s.insert(n);
        else
          return false;
         
        while(n>0){
        rem1= n%10;
        rem += (rem1*rem1);
        n=n/10;  
      }
         n=rem;
         rem=0;
 
   } 
      return true;
    }
};
