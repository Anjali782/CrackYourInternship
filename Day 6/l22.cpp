class Solution {
public:
    vector<string> valid;
    
    void generate(string &s , int o , int c){
     // o -openng bracket , c- closing bracket
        if(o==0 && c==0){
            return valid.push_back(s);
        }
        
        if(o>0){
            s.push_back('(');
            generate(s, o-1,c);
            s.pop_back();
        }
        if(c>0 && o<c){
            //o<c , means opening brackets in string is more than closing bracket than only i can put any closing bracket
            s.push_back(')');
            generate(s , o , c-1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        generate(s , n ,n);
        return valid;
    }
};
