class Solution {
public:
    int maxScore(vector<int>& c, int k) {
      int ans=0;
        int max=0;
       int l= c.size();
        int j=l-k;
        int start=0;
       for(int i=j;i<l;i++){
           ans += c[i];
       }
        max=ans;
        while(j<l){
        max = max-c[j++]+c[start++];
            if(max>ans){
                ans=max;
            }
        }
        return ans;
    }
};
