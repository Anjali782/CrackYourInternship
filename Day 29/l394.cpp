class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(int i=s.length()-1; i>=0; i--){
            if(s[i]==']')
            {  
                st.push("]");  
            }
            else if(s[i]=='['){
                string tm="";
                while(!st.empty() and st.top()!="]"){
                    tm+=st.top();
                    st.pop();
                }
                st.pop();i--;
                int g=1, x=0;
                while(i>=0){
                    if(!isdigit(s[i]))
                    {
                        break;
                    }
                    int xy = (s[i]-'0');
                    x+=(xy*g);
                    i--; g=g*10;
                }
                i++;
                string ans="";
                while(x--){
                    ans+=tm;
                }
                st.push(ans);
            }
            else{
                string tm = "";
                tm+=s[i];
                st.push(tm);
            }
        }
        string as = "";
        while(!st.empty()){
            as+=st.top();
            st.pop();
        }
        return as;
    }
};
