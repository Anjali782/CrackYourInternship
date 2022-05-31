class Solution {
public:
    string reverseWords(string s) {
    string ans;       
    int l=s.length(); 
    int count= -1;
    stack<string>st;
        
    for(int i=0;i<l;i++){
        int j=i;
        string temp="";
        if(s[j]!=' '){
        while(s[j]!=' ' && j<l){
         temp += s[j];
            j++;
        }
        st.push(temp);
       count++;
        i=j;    
        j++;
       }
    }
        
        while(!st.empty()){
         ans += st.top();
           st.pop();
          if(!st.empty() && count--)  
            ans += ' ';
        }
        
        ans += '\0';
        return ans;
    }
};
