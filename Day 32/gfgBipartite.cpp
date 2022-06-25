bool bipartitedfs(int node ,int G[][V] ,int color[] ){
 if(color[node]==-1){
   color[node]=1;
 } 
  for(auto it:G[node]){
   if(color[it]==-1){
   color[it]=1-color[node];
    if(!bipartitedfs(it,G,color)){
     return false;
    } 
   } 
  }
  return true;
}
bool isBipartite(int G[][V], int src)
{
  int color[V];
   memset(color , -1 , sizeof(color));
   for(int i=0;i<V;i++){
    if(color[i]!=-1){
     if(!bipartitedfs(i,G,color)){
      return false;
     }
    }
  }
  return true;
}
