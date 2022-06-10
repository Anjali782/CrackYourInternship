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
	vector<vector<int>> nearest(vector<vector<int>>M) {
	    int m=M.size();
	   int n=M[0].size();
	    queue <pair<int,int>> q;
	    vector <vector<int>> ans(m, vector <int> (n, -1));
	   for(int i=0;i<M.size();i++){
	       for(int j=0;j<M[0].size();j++){
	           if(M[i][j]==1){
	               q.push({i,j});
	               ans[i][j]=0;
	           }
	       }
	   }
	   
	   //bfs
	   while(!q.empty()){
	       int i=q.front().first;
	       int j=q.front().second;
	       //check for its neighours
	       if(checkValid(i+1 , j, m , n) && ans[i+1][j]==-1){
	          q.push({i+1 , j});
	          ans[i+1][j]= ans[i][j]+1;
	       }
	       if(checkValid(i-1 , j, m , n) && ans[i-1][j]==-1){
	         q.push({i-1 , j});
	          ans[i-1][j]= ans[i][j]+1;  
	       }
	       if(checkValid(i , j+1, m , n) && ans[i][j+1]==-1){
	         q.push({i , j+1});
	          ans[i][j+1]= ans[i][j]+1;  
	       }
	       if(checkValid(i , j-1, m , n) && ans[i][j-1]==-1){
	        q.push({i , j-1});
	          ans[i][j-1]= ans[i][j]+1;   
	       }
	       q.pop();
	   }
	   return ans;
	}
};
