class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans =0;
     int l=nums.size();
     vector<pair<int,int>>v;
     sort(nums.begin() , nums.end());
      int count=1;
        int i=0;
      for(i=0;i<l-1;i++){
        if(nums[i]==nums[i+1]){
            count++;
        }else{
            v.push_back( make_pair(count,nums[i]) );
            count=1;
        }  
      }
          v.push_back( make_pair(count,nums[i]) ); 
         sort(v.begin() , v.end());
         if(v[v.size()-1].first >= l/2){
           ans = v[v.size()-1].second ; 
         }
        return ans;
    }
};
