class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
     int sum1=INT_MIN;
     int sum2=INT_MAX;   
        int cursum=0;
        for(int i=0;i<nums.size();i++){
         cursum += nums[i];
           if(cursum>sum1){
               sum1=cursum;
           }
            if(cursum<0){
                cursum=0;
            }
        }
        cursum=0;
        for(int i=0;i<nums.size();i++){
         cursum += nums[i];
           if(cursum<sum2){
               sum2=cursum;
           }
            if(cursum>0){
                cursum=0;
            }
        }
        return max(sum1 , abs(sum2));
    }
};
