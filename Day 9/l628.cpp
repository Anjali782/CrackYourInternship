class Solution {
public:
    int maximumProduct(vector<int>& nums) {
     sort(nums.begin() ,nums.end());
      int s= nums.size();
      
       if(nums[0]<0 && nums[1]<0){
          return max(nums[0]*nums[1]*nums[s-1] , nums[s-1]*nums[s-2]*nums[s-3]);
       }
       else {
           return nums[s-1]*nums[s-2]*nums[s-3];
       } 
    }
};
