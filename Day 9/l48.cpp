class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size(); 
        
        //first do transpose of the matrix 
        //thr reverse the row elements;
        for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
            if(i>=j){
              swap(matrix[i][j],matrix[j][i]);
              }
           }
        }
        
        for(int i=0;i<n;i++){
            int j=m-1;
             int k=0; 
            while(k<j){
             swap(matrix[i][k],matrix[i][j]);
                j--;
                k++;
            }
        }
      
    }
};
