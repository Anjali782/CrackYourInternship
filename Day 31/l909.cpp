class Solution {
public:
    vector<int> findCoordinates(int boxNo , int n){
      int r= n-(boxNo-1)/n -1 ;//observe
      int c= (boxNo-1)%n;
        vector<int>v;
        if(r%2 == n%2){
            v.push_back(r);
            v.push_back(n-1-c);
        }else{
            v.push_back(r);
            v.push_back(c); 
        }
        return v;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
     int n=board.size();
     int steps=0;
        queue<int>q;
        vector<vector<bool>>vis(n , vector<bool>(n,false));
        q.push(1);
        
        vis[n-1][0] = true;
        while(!q.empty()){
            int size=q.size();
            
            for(int i=0;i<size;i++){
                int x= q.front();
                q.pop();
                if(x == n*n){
                    return steps;
                }
                for(int k=1;k<=6;k++){
                    if(k+x>n*n){
                        break;
                    }
                    vector<int>pos = findCoordinates(k+x , n);
                    int r=pos[0];
                    int c=pos[1];
                    if(vis[r][c]){
                        continue;
                    }
                    vis[r][c]=1;
                    if(board[r][c] == -1){
                        q.push(k+x);
                    }else{
                        q.push(board[r][c]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
