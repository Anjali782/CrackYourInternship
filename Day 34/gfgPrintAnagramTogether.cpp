class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& str) {
       vector<vector<string>>ans;
       unordered_map<string, vector<string>>m;
       for(int i=0; i<str.size(); i++) {
           string s = str[i];
           sort(str[i].begin(), str[i].end());
           m[str[i]].push_back(s);
       }
       for(auto &i : m) {
           ans.push_back(i.second);
       }
       return ans;
   }
};
