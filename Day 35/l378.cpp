class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
     priority_queue<int>m;
        for(int i=0;i<matrix.size();i++){
          for(int j=0;j<matrix.size();j++){
              m.push(matrix[i][j]);
              if(m.size()>k){
                  m.pop();
              }
          }
        }
        return m.top();
    }
};
