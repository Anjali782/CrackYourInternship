bool isvalid(int a[],int n,int cow ,int minDis)
{
 for(int i=0;i<n;i++){
  int lastPos=-1;
  if(a[i]-lastPos >= minDis || lastPos==-1){
   cows--;
    lastPos=i;
  } 
   if(cow==0)
     break;
 }
  if(cow==0) {
    return true;}
  rewturn false;   
}
     
     
class Solution 
{
    public:
    int findMinDistance(int a[], int n, int cows) 
    {
        int l= 0;
        int r=*max_element(a,a+n);
         sort(a , a+n);
       
        while(l+1<r)
        {
            int mid=l+(r-l)/2;
            if(isvalid(a,n,cows,mid))
            {
              l=mid;
            }
            else 
            {
                h=mid-1;
            }
        }
       if(isvalid(a,n,cows,h)){
         return h; 
        }
       return l; 
    }
};
