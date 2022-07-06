class Solution {
public:
    int search(vector<int>& nums, int target) {
     int j= nums.size();
     int i=0;
        while(i<j){
            int mid= i+(j-i)/2;
            if(nums[mid]<target){
                i=mid+1;
            }else if(nums[mid]>target){
                j=mid; 
            }else{
                return mid;
            }
        }
        return -1;
    }
};
