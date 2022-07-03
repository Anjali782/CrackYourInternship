class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
     if(nums.size()<=1){
         return nums.size();
     }
        
     int ans;
      if(nums[1]!=nums[0]){
          ans=2;
      }else{
          ans=1;
      }  
     stack<int>st;
     st.push(nums[1]-nums[0]);   
     for(int i=1;i<nums.size()-1;i++){
        int temp=nums[i+1]-nums[i];
         if(temp==0){
             continue;
         }
        if(st.top()<0){
          if(temp>0){
              ans++;
              st.pop();
          }else{
              st.pop();
          }
        }else if(st.top()>0){
          if(temp<0){
              ans++;
              st.pop();
          }else{
              st.pop();
          }   
        }else{
          ans++;
          st.pop();  
        }   
        st.push(temp);     
     } 
        return ans;
    }
};
