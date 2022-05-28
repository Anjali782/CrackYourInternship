class Solution {
public:
    bool canJump(vector<int>& nums) {
     int size= nums.size();
       int j=size-1;
        for(int i=size-2;i>=0;i--){
            if(i+nums[i]>=j)
                j=i;
        }
        if(j==0)
            return true;
        else
            return false;
    }
};

