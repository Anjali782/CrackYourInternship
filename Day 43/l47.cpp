class Solution {
public:
     bool checkSwap(vector<int>& nums,int start,int curr){
        for(int i=start; i<curr; i++)
            if(nums[curr] == nums[i])
                return false;
        return true;
    }
    void solve(int index, vector<int>& nums, vector<vector<int>>&ans){
        if(index==nums.size()){
            ans.push_back(nums);
        }
        
        for(int i=index;i<nums.size();i++){
            if(checkSwap(nums,index,i)){   
             swap(nums[i],nums[index]);
             solve(index+1 , nums, ans);
             swap(nums[i],nums[index]); 
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      vector<vector<int>>ans;
      solve(0,nums,ans);
        return ans;
    }
};
