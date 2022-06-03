class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    int l=0;
    int h=nums.size()-1;
        while(l<h){
          int mid =(l+h)/2 ;
          if(nums[mid]>nums[mid+1]){
             h =mid;}
          else{
             l=mid+1;
          }  
        }
        return l;
    }
};
