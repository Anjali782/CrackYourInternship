class Solution {
public:
    
    bool search(int r , int c ,vector<vector<char>>&board , int i, int j, string word , int position){
        if(position == word.length()-1){
            return true;
        }
        board[i][j] -=65;
        
        if(i>0 && board[i-1][j]== word[position+1] && search(r,c,board ,i-1, j,word , position+1)){
            return true;
        }
        if(j>0 && board[i][j-1]== word[position+1] && search(r,c,board ,i, j-1,word , position+1)){
            return true;
        }
        if(i<c-1 && board[i+1][j]== word[position+1] && search(r,c,board ,i+1, j,word , position+1)){
            return true;
        }
        if(j<r-1 && board[i][j+1]== word[position+1] && search(r,c,board ,i, j+1,word , position+1)){
            return true;
        }
        board[i][j] +=65;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
     int row =board[0].size();
     int col=board.size();
        for(int i=0;i<col;i++){
            for(int j=0;j<row;j++){
              if(board[i][j]==word[0] && search(row,col,board , i ,j ,word ,0)){
                 return true;}
            }
        }
                return false;
    }
};
