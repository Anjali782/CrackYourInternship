bool checkReverse(vector<int>&a, int n)
{
  vector<int>temp;
  temp=a;
  reverse(a.begin() , a.end());
  sort(temp.begin() , temp.end());
  int i=0;
  while(a[i] == temp[i] && i<n){
      i++;
  }
  if(i==n-1){
  return true;     
  }
  return false;
}
