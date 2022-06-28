class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
       int ans=0;
       int curSum=0;
       int start=0;
       int end=-1;
       unordered_map<int, int>mp;
       for(int i=0;i<n;i++){
           curSum += a[i];
           if(curSum==0){
               start=0;
               end=i+1;
               ans = max(ans , end-start);
           }
           if(mp.find(curSum)!=mp.end()){
               start=mp[curSum];
               end=i;
               ans = max(ans , end-start);
           }
           mp.insert({curSum , i});
       }
       if(end==-1){
           return 0;
       }
       return ans;
    }
};
