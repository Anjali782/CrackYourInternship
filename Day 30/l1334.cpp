class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
//dis of city 0 to all 0-1(3) , 0-2(4) , 0-3(5) , threshold is 4 then only two city within th threshold similarly we have to find the no. of cities coming under threshold distance , give ans as minimum of them
        
//first we build the table using floyd warshall method    
//make a matrix and all the dis as infinite except diagonal because from 1 to 1 dis is 0
  vector<vector<int>>dis(n , vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            dis[i][i]=0;
        }
        for(vector<int>v : edges){
            dis[v[0]][v[1]] = v[2];
            dis[v[1]][v[0]] = v[2];//because undirected graph
        }
//we will modify dis for all node like using 0, if dis[1][0]+dis[0][2] < dis[1][2] modify it     //similarly using 1 then 2 then 3 if we can find the dis.      
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
             if(dis[i][k]!=INT_MAX && dis[k][j]!=INT_MAX && dis[i][k]+dis[k][j] <dis[i][j]){
                 dis[i][j]= dis[i][k]+dis[k][j];
             }    
            }
        }
    }
    int city=INT_MAX;
    int ans;
    //find city under threshold     
    for(int i=0;i<n;i++){
     int count=0;
      for(int j=0;j<n;j++){
       if(i!=j && dis[i][j]<=distanceThreshold){
           count++;
       }   
      }
     if(count<=city){
         ans=i;
         city=count;
     }
    }
        return ans;
    }
};
