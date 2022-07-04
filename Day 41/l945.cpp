class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int nextReq=INT_MIN;
        int res=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){``
            if(nums[i]<nextReq){
                res+=(nextReq-nums[i]);
                nums[i]=nextReq;
            }
            nextReq=nums[i]+1;
        }
        return res;
    }
};
