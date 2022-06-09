class Solution {
public:
bool backspaceCompare(string s, string t) {
    stack<char> s1, s2;
    for(int i=0;i<s.length();i++){
        if(s[i]!='#'){
            s1.push(s[i]);
        }
        else if(s[i]=='#' && !s1.empty()){
            s1.pop();
        }
    }
    for(int j=0;j<t.length();j++){
        if(t[j]!='#'){
            s2.push(t[j]);
        }
        else if(t[j]=='#' && !s2.empty()){
            s2.pop();
        }
    }
    int x=s1.size();
    int y=s2.size();
    
    if(x==y){
        for(int k=0;k<x;k++){
            if(s1.top()!=s2.top()){
                return false;
            }
            else{
                s1.pop();
                s2.pop();
            }
        }
        return true;
    }
    else{
        return false;
    }
  }
};
