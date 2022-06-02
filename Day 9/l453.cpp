class Solution {
public:
   int minMoves(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      int count=0;
      int p = nums[0];
      int size=nums.size();
       
      for(int i=0;i<size;i++)
      {
        count+=nums[i]-p;
      }
      return count;
   }
};
