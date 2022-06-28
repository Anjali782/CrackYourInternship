class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     sort(nums.begin() , nums.end());
        int l=nums.size();
        vector<int>p;
        vector< pair<int,int>> v;
        if(l==1){
        p.push_back(nums[0]);
            return p;
        }
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
        int size = v.size();
        for(int i=size-1 ; i>size-k-1 ;i--){
            p.push_back(v[i].second); 
        }
        return p;
    }
};
