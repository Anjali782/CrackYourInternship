class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int size= nums.size();
        if(size<4){
            return ans;
        }
      sort(nums.begin(),nums.end());
       for(int i=0;i<size;i++){
           if(i>0 && nums[i]==nums[i-1]){
               continue;
           }
          for(int j=i+1;j<size;j++){
           if(j>i+1 && nums[j]==nums[j-1]){
               continue;
           } 
           int preTwoSum = target - nums[i]-nums[j];
            int low=j+1;
            int high =size-1;
              while(low<high){
                
                  int postTwoSum =nums[low] + nums[high];
                  if(postTwoSum < preTwoSum){
                      low++;
                  }else if(postTwoSum > preTwoSum){
                      high--;
                  }else{
                    vector<int>ans1;
                    ans1.push_back(nums[i]);
                    ans1.push_back(nums[j]);
                    ans1.push_back(nums[low]);
                    ans1.push_back(nums[high]);
                    if(find(ans.begin(),ans.end(),ans1) == ans.end()){  
                    ans.push_back(ans1);}
                    low++;
                    high--;
                     
                  }
                    
              }
          } 
       }
       return ans; 
    }
};


				
