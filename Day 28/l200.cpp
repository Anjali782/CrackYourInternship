class Solution {
public:
    
    void solve(vector<vector<char>>& grid , int i , int j){
       if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
           return;
       }
           if(grid[i][j]=='0'){
               return ;
           }
           //else we will make 1 -> 0 and call its neighous
           grid[i][j]='0';
           solve(grid , i+1, j);
           solve(grid , i-1, j);
           solve(grid , i, j+1);
           solve(grid , i, j-1); 
    }
    int numIslands(vector<vector<char>>& grid) {
     int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size() ;j++){
              if(grid[i][j]=='1'){
                  solve(grid , i ,j);
                  count++;    
              }  
            }
        }
        return count;
    }
};
