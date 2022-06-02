class Solution {
public:
    int missingNumber(vector<int>& nums) {
     int n=nums.size();   
     int a[n+1];
     memset(a , 0 , sizeof(a));
     for(int i=0;i<n;i++){
         a[nums[i]]++;
     }
     for(int i=0;i<n+1;i++){
         if(a[i]==0)
             return i;
     } 
        return 0;
    }
};
