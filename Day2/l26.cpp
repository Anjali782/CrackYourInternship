class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      if(nums.size()==0)
            return 0;
        
        int ind=1;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
                continue;
            else
            {
                nums[ind]=nums[i];
                ind++;
            }
        }
        nums.erase(nums.begin()+ind, nums.end());
      
        return nums.size();
    }
};
