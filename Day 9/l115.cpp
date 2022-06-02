class Solution {
public:
    int numDistinct(string s, string t) {
     long long int m= t.length();
     long long int n= s.length();   
     unsigned long long int T[m+1][n+1]; 
        
        for(long long int j=0;j<n+1;j++){
            T[0][j]=1;
        }for(long long int j=1;j<m+1;j++){
            T[j][0]=0;
        }

        for(long long int i=0;i<m;i++){
          for(long long int j=0;j<n;j++){
             if(t[i]==s[j]){
                 T[i+1][j+1]= T[i][j] + T[i+1][j]; 
              }
              else{
                T[i+1][j+1]=T[i+1][j];   
              }
          }
        }
        return T[m][n];
    }
};
