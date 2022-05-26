class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count=0;
       int currSum =0;
       unordered_map<int , int> m;
        m[0]=1;
       for(int i=0;i<nums.size();i++){
        currSum= currSum +nums[i];
           int rem = currSum % k;
           if(rem<0) 
               rem = rem+k;
            if(m.find(rem)!=m.end()){
                count+=m[rem];
            }
            m[rem]++;
        }
        return count;
    } 
};
