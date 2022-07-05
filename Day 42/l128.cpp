class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    sort(nums.begin() , nums.end());
        int ans=INT_MIN;
        int count=1;
        if(nums.size()<=1){
            return nums.size();
        }
        for(int i=0;i<nums.size()-1;i++){
            if(abs(nums[i+1]-nums[i])==1){
                count++;
            }
            if(abs(nums[i+1]-nums[i])==0){
               continue;
            }
            ans= max(ans , count);
            
            if(abs(nums[i+1]-nums[i])!=1){
                count=1;
            }
        }
        return ans==INT_MIN ? 1:ans;
    }
};
