class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
      int row = m.size();
        int col = m[0].size();
      vector<vector<int>>matrix = m;  
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                  for(int k=0;k<col;k++){
                      m[i][k]=0;
                  }
                  for(int k=0;k<row;k++){
                    m[k][j]=0;
                  }
                }
            }
        }
    }
};
