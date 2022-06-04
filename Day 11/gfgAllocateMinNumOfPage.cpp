bool isvalid(int a[],int n,int k,int mx)
{
    int stud=1;
    int sm=0;
    for(int i=0;i<n;i++)
    {
        sm+=a[i];
        if(sm>mx)
        {
            stud++;
            sm=a[i];
        }
        if(stud>k)
        {
            return false;
        }
    }
    return true;
}
class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m) 
    {
        //code here
        int l= *max_element(a,a+n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
        }
        int r=sum;
        int res=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            int mx=mid;
            if(isvalid(a,n,m,mx))
            {
                res=mid;
                r=mid-1;
            }
            else 
            {
                l=mid+1;
            }
        }
        return res;
    }
};
