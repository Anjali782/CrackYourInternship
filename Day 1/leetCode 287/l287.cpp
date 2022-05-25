class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int size=nums.size();
        int arr[size];
        for(int i=0;i<size;i++){
            arr[i]=0;
        }
        for(int i = 0;i<size ; i++){
            if(arr[nums[i]]== 0){
                arr[nums[i]]++;
            }else{
                return nums[i];
            }
        }
        return 0;
    }
};
