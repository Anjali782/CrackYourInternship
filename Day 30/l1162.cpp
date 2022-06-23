class Solution {
public:
    int dx[4]={0,0,-1,1};
    int dy[4]={1,-1,0,0};
    
    int maxDistance(vector<vector<int>>& grid) {
    int n= grid.size();
    int m=grid[0].size();
        
     vector<vector<int>>dis(n,vector<int>(m ,INT_MAX));
     queue<pair<int , int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dis[i][j]=0;
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int xx=x+dx[i];
                int yy= y+dy[i];
                
                if(xx >=0 && xx<n && yy>=0 && yy<m && dis[xx][yy]==INT_MAX){
                    q.push({xx, yy});
                    dis[xx][yy]=dis[x][y]+1;
                    ans = max(ans , dis[xx][yy]);
                }
            }
        }
        if(ans == INT_MAX || ans== 0){
            return -1;
        }
        return ans;
    }
};
