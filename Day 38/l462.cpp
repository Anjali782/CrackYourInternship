class Solution {
public:
    int minMoves2(vector<int>& nums) {
     sort(nums.begin() , nums.end());
        int n=nums.size();
        int mid= n/2;
        
        int ans=0;
        for(int i=0;i<n;i++){
            ans += abs(nums[i]-nums[mid]);
        }
        return ans;
    }//1 10 2 9, 1 2 9 10, 8 7 0 1
};
