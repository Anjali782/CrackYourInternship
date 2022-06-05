class Solution {
public:
    bool isvalid(vector<int>&nums,int n, int max , int m){
     int split=1;
     int sm =0;
    for(int i=0;i<n;i++){
        sm += nums[i];
        if(sm>max){
            split++;
            sm= nums[i];
        }
        if(split>m){
            return false;
        }
    }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
     int n= nums.size();   
     int l= *max_element(nums.begin() , nums.end());
     int sum=0; 
        
     for(int i=0;i<n;i++){
         sum += nums[i];
     }
     
     int ans=-1; 
     int r=sum;
        
     while(l<=r){
     int mid = (l+r)/2;
         
      if(isvalid(nums ,n, mid, m)){
          ans= mid;
          r= mid-1;
      }else{
          l =mid+1;
      }   
     }  
      return ans;  
    }
};
