class Solution {
public:
    int kthFactor(int n, int k) {
    if(k==1){
        return 1;
    }
    int div=2;
    int count=1;
    while(div<n+1){
     if(n%div==0){
         count++;
     }
     if(count==k){
         return div;
     }div++;   
    } 
      return -1;  
    }
};
