#include <iostream>
using namespace std;

int getMax(vector<int> arr){
    int mx=a[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i]>mx){
            mx=arr[i];
        }
    }
    return mx;
}

vector<int> countSort(vector<int>arr,int exp){
 vector<int>output[arr.size()];    
 int count[10]={0};
 
 for(int i=0;i<n;i++){
     count[(arr[i]/exp)%10]++;
 }
 
 for(int i=1;i<10;i++){
     count[i] += count[i-1];
 }
 
 for(i = arr.size() - 1; i >= 0; i--){
    output[count[(arr[i]/exp)%10]-1] =arr[i];
    count[(arr[i]/exp)%10]--;
 }
 return output;
 
}

void radixsort(vector<int>arr)
{
    int m = getMax(arr);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr,exp);
}
