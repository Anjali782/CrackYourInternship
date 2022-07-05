class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
     int m=heights.size();
     int n=heights[0].size();
       int vis[m][n];
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               vis[i][j]=INT_MAX;
           }
       } 
       priority_queue<pair<int , pair<int , int>>,vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>>>pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int x=it.second.first;
            int y=it.second.second;
            int dis = it.first;
            
            int dx[4]={-1,1,0,0};
            int dy[4]={0,0,-1,1};
            for(int i=0;i<4;i++){
              int xx= x+dx[i];
              int yy= y+dy[i];
          if(xx>=0 && xx<m && yy>=0 && yy<n){
             int newDist = max(dis , abs(heights[x][y]-heights[xx][yy]));
              if(vis[xx][yy]>newDist){
                 vis[xx][yy]=newDist;
               pq.push({newDist , {xx,yy}});    
              }
          }
            }
        }
        return vis[m-1][n-1]==INT_MAX?0:vis[m-1][n-1];
    }
};
