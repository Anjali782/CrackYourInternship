class Solution {
public:
    int t[101][101];
    bool solve(string s1, string s2, string s3 , int i , int j , int k){
     if(k==s3.size()){
         return true;
      } 
        if(t[i][j]!=-1){
            return t[i][j];
        }
         if(i<s1.size() && s3[k] == s1[i] && (j>=s2.size() || s3[k] != s2[j])){
           return t[i][j]= solve(s1,s2,s3,i+1,j,k+1);  
         } 
         if(j<s2.size() && s3[k] == s2[j] && (i>=s1.size() || s3[k] != s1[i])){
           return t[i][j]= solve(s1,s2,s3,i,j+1,k+1);  
         }
        else if(j<s2.size() && i<s1.size() && s3[k] == s2[j] && s3[k] == s1[i]){
           return t[i][j] = solve(s1,s2,s3,i+1,j,k+1) || solve(s1,s2,s3,i,j+1,k+1);  
         }
        else{
           return false;
         } 
        return t[i][j];
    }
    bool isInterleave(string s1, string s2, string s3) {
     int i=0, j=0 , k=0; 
      memset(t,-1,sizeof(t));   
      if(s3.size() != s1.size()+s2.size()){
          return false;
      }  
      return solve(s1,s2,s3,i,j,k);  
    }
};

