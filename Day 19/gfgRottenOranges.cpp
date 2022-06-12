class Solution
{
    public:
     bool checkValid(int i , int j , int m , int n){
        if(i<0 || j<0 || i>=m || j>=n){
            return false;
        }
        return true;
    }
  
    //Function to find distance of nearest 1 in the grid for each cell.
	int orangesRotting(vector<vector<int>>&M) {
	    int m=M.size();
	   int n=M[0].size();
	   
	    queue <pair<int,int>> q;
	    vector <vector<int>> ans(m, vector <int> (n, -1));
	    
	   for(int i=0;i<M.size();i++){
	       for(int j=0;j<M[0].size();j++){
	           if(M[i][j]==2){
	               q.push({i,j});
	               ans[i][j]=0;
	           }if(M[i][j]==0){
	               ans[i][j]=-2;
	           }
	       }
	   }
	   
	   //bfs
	   while(!q.empty()){
	       int i=q.front().first;
	       int j=q.front().second;
	       //check for its neighours
	       if(checkValid(i+1 , j, m , n) && ans[i+1][j]==-1 && ans[i+1][j]!= -2){
	          q.push({i+1 , j});
	          ans[i+1][j]= ans[i][j]+1;
	       }
	       if(checkValid(i-1 , j, m , n) && ans[i-1][j]==-1 &&  ans[i-1][j]!=-2){
	         q.push({i-1 , j});
	          ans[i-1][j]= ans[i][j]+1;  
	       }
	       if(checkValid(i , j+1, m , n) && ans[i][j+1]==-1 && ans[i][j+1]!=-2){
	         q.push({i , j+1});
	          ans[i][j+1]= ans[i][j]+1;  
	       }
	       if(checkValid(i , j-1, m , n) && ans[i][j-1]==-1 &&  ans[i][j-1]!=-2){
	        q.push({i , j-1});
	          ans[i][j-1]= ans[i][j]+1;   
	       }
       	       q.pop();
       	}
       	    int mx=INT_MIN;
         for(int i=0; i<m; i++){
             for(int j=0; j<n; j++){
                 mx=max(mx,ans[i][j]);
                 if(ans[i][j]==-1){
                   return -1;  
                 }
             }
         }
         if(mx == 0)
           return -1;
         return mx;
	}
};
