int arrayElementEqual(vector<int>arr)
{
 int ans=INT_MAX;
 for(int i=0;i<arr.size();i++){
      int Min=0;
   for(int j=0;j<arr.size();j++){
    Min = Min + abs(arr[i]-arr[j]);   
   }
  ans = min(ans,Min);
 }
 return ans;
}
