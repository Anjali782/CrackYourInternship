class Solution
{
    public:
    
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    
	    queue<pair<int,int>> q;
	    q.push({KnightPos[0],KnightPos[1]});
	    vector<vector<int>> dist(N+1,vector<int>(N+1,0));
	    int dx[] = {-1,-2,-2,-1,1,1,2,2};
	    int dy[] = {-2,-1,1,2,-2,2,-1,1};
	    while(!q.empty()){
	        int size=q.size();
	        for(int c=0;c<size;c++){
	            auto temp = q.front();
	            q.pop();
	            if(temp.first==TargetPos[0] && temp.second==TargetPos[1])
	                return dist[temp.first][temp.second];
	            for(int k=0;k<8;k++)     {
	                int i = temp.first+dx[k];
	                int j= temp.second+dy[k];
	                if(i>0 && i<=N && j>0 && j<=N && dist[i][j]==0){
	                    dist[i][j]=dist[temp.first][temp.second]+1;
	                    q.push({i,j});
	                }
	            }
	                
	        }
	    }
	    return dist[TargetPos[0]][TargetPos[1]];
	}
};
