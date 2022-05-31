class Solution {
public:
    string simplifyPath(string p) {
        int l=p.size();
        stack<string>s;
        string ans;
      
        for(int i=0;i<l;i++){
            if(p[i]=='/')
               continue;
            string temp;
            while(i<l && p[i]!='/'){
                temp = temp+p[i];
                i++;
            }
            if(temp == "."){
                continue;
            }else if(temp==".."){
                if(!s.empty()){
                    s.pop();
                }
            }else{
                s.push(temp);
            }
        }
           while(!s.empty())
        {
            ans = "/" + s.top() + ans;
            s.pop();
        }
        
         if(ans.size() == 0)
            return "/";
        
        
        return ans;
    }
};
