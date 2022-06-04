int minSwap(int arr[] , int n){
pair<int , int>p[n];
  for(int i=0;i<n;i++){
    p.first = a[i];
    p.second= i;
  }
  sort(p , p+n);
  vector<bool> v(n, false);
  int ans = 0;
  
  for(int i=0;i<n;i++){
    if(v[i] || p[i].second = i){
      continue;}
    
    int cycle = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;
            j = p[j].second;
            cycle++;
        }
    if (cycle > 0)
        {
            ans += (cycle- 1);
        }
   } 
  return ans;
}
