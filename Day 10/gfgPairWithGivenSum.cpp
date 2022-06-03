bool findPair(vector<int>arr, int size, int n)
{
    sort(arr.begin() , arr.end());
    int i = 0;
    int j = size-1;
    while (i < j)
    {
       if(arr[j]-arr[i] < n){
         j--;}
       if(arr[j]-arr[i]> n){
         i++;}
       else{
         cout<<arr[i]<<" "<<arr[j];
         return true;
       }
    }
 
    cout << "No such pair";
    return false;
}
