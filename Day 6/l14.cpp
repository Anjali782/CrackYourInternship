class Solution {
public:

    string longestCommonPrefix(vector<string>& strs) {
        if(strs[0] == ""){
            return "";
        }
        string ans = strs[0];
        if(strs.size() >1)
        {
            string s;
            for(int i=1;i<strs.size();i++)
            {
                s=strs[i];
                int j=0;
                while(ans[j] == s[j] && j<ans.size())
                    j++;
                ans.resize(j);
                if(j==0)
                 return "";
            }
        }
        return ans;
    }
     
};
