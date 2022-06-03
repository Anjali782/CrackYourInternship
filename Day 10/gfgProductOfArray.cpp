vector<int> productArray(vector<int>arr)
{
 
    if (n == 1) {
        cout << 0;
        return;
    }
  
    vector<int>left[arr.size()];
    vector<int>right[arr.size()];
    vector<int>ans[arr.size()];

    left[0] = 1;
    right[arr.size()- 1] = 1;
 
    for (int i = 1; i < n; i++){
        left[i] = arr[i-1]*left[i-1];
    }
    for (int i = arr.size()-2; i>=0; i--){
       rightt[i] = arr[i+1]*right[i+1];
    }
 
    for (int i = 0; i < n; i++){
        ans[i] = left[i] * right[i];
    }
    return ans;
}
