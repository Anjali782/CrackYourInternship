class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size(), ans = 0;;
        vector<int> st;
        for (int i = 0; i < n; ++i) {
            int leaf = 0;
            while(!st.empty() && st.back() < arr[i]) {
                ans += leaf * st.back();
                leaf = st.back(); 
                st.pop_back();
            }
            ans += leaf * arr[i];
            st.push_back(arr[i]);
        }
        for(int i = 0; i < st.size() - 1; ++i) {
            ans += st[i] * st[i + 1];
        }
        return ans;
    }
};
