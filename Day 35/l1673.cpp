class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) 
    {
        stack<int> st;
        int n=nums.size();
        int size=1;
        
        st.push(nums[0]);
        for(int i=1;i<n;i++){
            int left=n-i;
            while(!st.empty() and st.top()>nums[i] and k-size<left){
                st.pop();
                size--;
            }
            if(size<k){
                st.push(nums[i]);
                size++;
            } 
        }
    
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
