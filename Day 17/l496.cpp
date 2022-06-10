class Solution
{
    public:
        vector<int> nextGreaterElement(vector<int> &findNums, vector<int> &nums)
        {
            unordered_map<int, int> m;
            int n = nums.size();
            stack<int> st;

            for (int i = n - 1; i >= 0; --i)
            {
                while (!st.empty() && st.top() <= nums[i]){
                    st.pop();
                }
                if (!st.empty()){
                    m[nums[i]] = st.top();
                }
                else{
                    m[nums[i]] = -1;
                }
                st.push(nums[i]);
            }

            vector<int> ans;
            for (int n: findNums){
                ans.push_back(m[n]);
            }
            return ans;
        }
};
