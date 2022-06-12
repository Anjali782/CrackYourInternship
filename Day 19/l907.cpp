class Solution {
public:
   int sumSubarrayMins(vector<int>& arr) {
       
     int size=arr.size();
     stack<int>stk;
     stk.push(-1);
     long long int ans=0;
     long long int mod=1000000007;
     vector<int>left(size) , right(size);
       
     for(int i=0;i<size;i++){
         while(!stk.empty() && stk.top()!=-1 && arr[stk.top()]>=arr[i]){
             stk.pop();
         }
         if(!stk.empty()){
             left[i] = i-stk.top();
         }
         stk.push(i);
     }
      
      while(!stk.empty()){
          stk.pop();
      }
      stk.push(size); 
       
      for(int i=size-1;i>=0;i--){
         while(!stk.empty() && stk.top()!=size && arr[stk.top()]>arr[i]){
             stk.pop();
         }
         if(!stk.empty()){
             right[i] = stk.top()-i;
         }
         stk.push(i);
     }
       for(int i=0;i<size;i++){
            ans=(ans%mod+((arr[i]%mod*left[i]%mod)%mod*right[i]%mod)%mod)%mod;
       }
       return ans;
    }
};     
