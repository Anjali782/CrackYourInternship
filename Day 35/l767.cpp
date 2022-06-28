class Solution {
public:
    string reorganizeString(string s) {
      unordered_map<char , int>mp;
        priority_queue<pair<int , char>>pq;
        
        string ans="";
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        for(auto &it:mp){
           pq.push({it.second,it.first});
        }
        while(pq.size()>1){
          auto top1=pq.top();
            pq.pop();
          auto top2=pq.top();
            pq.pop(); 
          
          ans += top1.second;
          ans += top2.second; 
            
            if(--top1.first>0){
                pq.push(top1);
            }
            if(--top2.first>0){
                pq.push(top2);
            }
        }
        if(pq.size()){
          auto top=pq.top();  
          if(top.first==1){
            ans += top.second;  
          }else{
              return "";
          }  
        }
        return ans;
    }
};
