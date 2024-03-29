class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
     int n=grid.size();
     //creat a min heap   
     priority_queue<pair<int, pair<int, int>>, vector< pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    // a vis array to keep record of visited indexes
    vector<vector<bool>>vis(n,vector<bool>(n,false));
    pq.push({grid[0][0],{0,0}});
    vis[0][0]=true;
    int ans=grid[0][0];
    
    while(!pq.empty())
    {
        //min value is on front from all directions to take it
        int value=pq.top().first;
        int i=pq.top().second.first;
        int j=pq.top().second.second;
        pq.pop();
        //now we want the max stoppage
        ans=max(ans,value);
        
        //base case
        if(i==n-1 and j==n-1)
        {
            break;
        }
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        
        for(int idx=0;idx<4;idx++)
        {
            int newi=i+dx[idx];
            int newj=j+dy[idx];
            
            if(newi>=0 and newi<n and newj>=0 and newj<n and !vis[newi][newj])
            {
                vis[newi][newj]=true; 
                //put all direction element in min heap which are not visited
                pq.push({grid[newi][newj],{newi,newj}});
            }
        }
        
    }
    
    return ans;  
    }
};
