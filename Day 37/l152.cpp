class Solution {
public:
    int maxProduct(vector<int>& nums) {
     int n= nums.size();
       int curP=1;
       int maxP=INT_MIN;
        for(int i=0;i<n;i++){
            curP= curP*nums[i];
            maxP=max(maxP,curP);  
            if(curP==0){
                curP=1;
            }
        }
        curP=1;
        for(int i=n-1;i>=0;i--){
            curP= curP*nums[i];
             maxP=max(maxP,curP); 
            if(curP==0){
                curP=1;
            }
        }
        return maxP;
    }
};
