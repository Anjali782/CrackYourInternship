class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
     deque<int>dq;//take a data structure which can add and remove from both side , it will contain index no.
     vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(!dq.empty() && dq.front()==i-k){
                dq.pop_front();//removing extra element from window
            }
            while(!dq.empty() && nums[dq.back()]<nums[i]){//if prev no. is less than next in window than remove
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);//if index is window-1 then push ele in ans
            }
        }
        return ans;
    }
};
