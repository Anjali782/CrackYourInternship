class Solution {
public:
    int maxArea(int x, int y, vector<int>& h, vector<int>& v) {
     ios_base::sync_with_stdio(false);
        cin.tie(NULL);   
        
     sort(h.begin(),h.end());
     h.push_back(x);
        vector<int>temph=h;
     sort(v.begin(),v.end());
     v.push_back(y);
        vector<int>tempv=v;
      for(int i=1;i<h.size();i++){
         h[i]=temph[i]-temph[i-1]; 
      }
      for(int i=1;i<v.size();i++){
         v[i]=tempv[i]-tempv[i-1]; 
      }
        long long int mh=INT_MIN;
        long long int mv=INT_MIN;
      for(int i=0;i<h.size();i++){
         if(h[i]>mh){
             mh=h[i];
         } 
      }
      for(int i=0;i<v.size();i++){
         if(v[i]>mv){
             mv=v[i];
         } 
      }
        long long ans = ((mh%1000000007)*(mv%1000000007))%1000000007 ;
        return ans;
    }
};
