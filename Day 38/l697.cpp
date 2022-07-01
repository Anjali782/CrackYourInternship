class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
     unordered_map<int,vector<int>>mp;
        int mx=0;
        int mn=nums.size();
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
            int size= mp[nums[i]].size();
            mx=max(size , mx);
        }
        for(auto it:mp){
            if(it.second.size()== mx){
                int ans = it.second[it.second.size()-1]-it.second[0]+1;
                mn= min(mn , ans);
            }
        }
        return mn;
    }
};
