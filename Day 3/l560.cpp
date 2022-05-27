class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int size=nums.size();
        unordered_map<int,int>m ;
        int curSum=0;
        int count =0;
        m[0]=1;
       
        for(int i=0;i<size;i++){
            curSum += nums[i];
           
            if(m.find(curSum-k)!=m.end()){
                count+=m[curSum-k];
            }
            m[curSum]++;
        }
        return count;
    }
};
