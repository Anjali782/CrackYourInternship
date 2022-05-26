class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size=nums.size();
       for (int i=0, j = 0;i<size;i++)
		if (nums[i] != 0)
			swap(nums[j++], nums[i]);
    }
};
