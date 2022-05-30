class Solution {
public:
    void gameOfLife(vector<vector<int>>& b) {
       int c=b[0].size();
        int r=b.size();
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
              int l=0; 
                
             if(i>0 && b[i-1][j]>=1){l++;}
             if(i<r-1 && b[i+1][j]>=1){l++;}    
             if(j>0 && b[i][j-1]>=1){l++;}
             if(j<c-1 && b[i][j+1]>=1){l++;}
                
             if(i>0 && j>0 && b[i-1][j-1]>=1){l++;}
             if(i>0 && j<c-1 && b[i-1][j+1]>=1){l++;}   
             if(i<r-1 && j<c-1 && b[i+1][j+1]>=1){l++;}
             if(i<r-1 && j>0 && b[i+1][j-1]>=1){l++;}
                
              if(b[i][j]==1 &&( l<2 || l>3)){
                  b[i][j]=2;
              }
              if(b[i][j]==0 && l==3){
               b[i][j]=-1;   
              }  
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
              if(b[i][j]==2){
                  b[i][j]=0;
              }if(b[i][j]== -1){
                  b[i][j]=1;
              }
            }
        }
    }
};   
