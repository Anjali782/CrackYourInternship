class Solution {
public:
    string removeDuplicates(string s, int k) {
     stack<pair<char , int>>stk;
        
     for(int i=0;i<s.length();i++){
         if(stk.empty() || stk.top().first != s[i]){
             stk.push({s[i],1});
         }
         else if(stk.top().first == s[i]){
             auto top = stk.top();
             stk.pop();
             stk.push({s[i] ,top.second+1});
         }
         if(stk.top().second == k){
            stk.pop(); 
         }
     } 
       string ans; 
     
        while(!stk.empty()){
            auto top = stk.top(); 
            for(int i = 0; i<top.second; ++i)
                ans += top.first; 
            stk.pop(); 
        }
       
        reverse(ans.begin(), ans.end()); 
        return ans; 

    }
};
