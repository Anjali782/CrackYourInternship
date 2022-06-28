class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
   { 
       vector<int> freq(n+1);
       for(int i = 0; i < n; i++)
       {
           if(arr[i] < 0 || arr[i] > n) continue;
           freq[arr[i]]++;
       }
       for(int i = 1; i <= n; i++)
       {
           if(freq[i] == 0) return i;
       }
       return n+1;
   }
};
