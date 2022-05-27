class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size= nums.size();
      sort(nums.begin() , nums.end());
       vector<vector<int>>ans;
        if(size<3){
            return ans;
        }
        for(int i =0 ; i<size-2 ; i++){
            int j=i+1;
            int k=size-1;
            while(j<k){
                if(nums[j]+nums[k] == -1*(nums[i])){
                    vector<int>ans1;
                    ans1.push_back(nums[i]);
                    ans1.push_back(nums[j]);
                    ans1.push_back(nums[k]);
                    ans.push_back(ans1);
                    while(j<k && nums[j]==nums[j+1]){
                            j++;
                        }
                    while(j<k && nums[k]==nums[k-1]){
                            k--;}
                    j++;
                    k--;
                }else if(nums[j]+nums[k] > -1*(nums[i])){
                    k--;
                }else{
                    j++;
                }
            }
            while(i<size-2 && nums[i+1]==nums[i]){
                            i++;}
        }
        return ans;
    }
};
