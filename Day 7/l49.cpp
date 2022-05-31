class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     int l=strs.size();  
      unordered_map<string , vector<string>>m;
       string temp; 
      for(int i=0;i<l;i++){
       temp = strs[i];
       sort(temp.begin() , temp.end());
        m[temp].push_back(strs[i]);
     }   
        vector<vector<string>> ans;
        for(auto i=m.begin() ; i!=m.end() ;i++){
            ans.push_back(i->second);
        }
        
        return ans;
    }
};
