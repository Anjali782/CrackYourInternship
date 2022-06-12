class Solution {
public:
    bool isOperator(string s){
        if(s=="+" || s=="-" || s=="*" || s=="/")
            return true;
        return false;
    }
    
    int evalRPN(vector<string>& tokens) {
     stack<int>stk;
     
      
     for(int i=0;i<tokens.size();i++){ 
       if(!isOperator(tokens[i]))
       {
          stk.push(stoi(tokens[i])); 
       }
    
       else{
           int b=stk.top();
           stk.pop();
           int a=stk.top();
           stk.pop();
           int res=0;
           
           if(tokens[i]=="+") 
              res=a+b; 
           if(tokens[i]=="-") 
              res=a-b;
           if(tokens[i]=="*") 
              res=a*b; 
            if(tokens[i]=="/") 
              res=a/b;
           
          
          stk.push(res);  
        } 
     } 
     return stk.top();   
        
    }
};
