
class Solution {
public:
    bool isValid(string s) {
        
     stack<char> stk;
    for(int i=0;s[i]!='\0';i++){
        
     if(s[i] == '(' || s[i] =='['|| s[i] == '{' )
     {
         stk.push(s[i]);
      }
        
        else if( s[i] == ')' || s[i] ==']'|| s[i] == '}' )
        {
           
        if(s[i]==')' && !stk.empty() && stk.top()=='('){
                stk.pop();
            }
         else if(s[i] == '}' && !stk.empty()  && stk.top() == '{'){
                stk.pop();
            }
          else if(s[i] == ']' && !stk.empty()  && stk.top() == '['){
                stk.pop();
            }
            
           else{
                return 0;
              }
          }                        
        }
        if(stk.empty()){
            return 1;
        }else{
            return 0;
        }
    }
};
