class Solution {
    const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0}; //direction array
public:
    bool isValid(int x,int y,int n,int m)
    {
        if(x>=n||x<0||y>=m||y<0)
            return 0;
        return 1;
    }
    int siz=0;
    void dfs(int x,int y,int n,int m,int counter,vector<vector<int>>&grid){
        grid[x][y]=counter; //labeling cell
        siz++;
        for(int i=0;i<4;i++)
        {
            int X=x+dx[i];
            int Y=y+dy[i];
            if(isValid(X,Y,n,m))
            {
                if(grid[X][Y]==1)
                dfs(X,Y,n,m,counter,grid);
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int counter=2;
        vector<int>arr;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                
                if(grid[i][j]==1)
                {
                    siz=0;
                    dfs(i,j,n,m,counter,grid);
                    arr.push_back(siz);
                    ans=max(ans,siz);
                    counter++;
                }
                
            }
        }
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    set<int>s;
                    int temp=1;
                    for(int k=0;k<4;k++)
                    {
                        int x=i+dx[k],y=j+dy[k];
                        if(isValid(x,y,n,m))
                        {
                            if(grid[x][y])
                            s.insert(grid[x][y]);
                        }
                    }
                    for(auto &it:s)
                    {
                        
                        temp+=arr[it-2];
                    }
                    ans=max(ans,temp);
                }
                     
            }
            
        }
        return ans;
    }
};
