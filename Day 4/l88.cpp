class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i=0,j=0;
       queue<int> q;
        while(i<m && j<n){
            if(nums1[i] > nums2[j]){
                q.push(nums2[j]);
                    j++;
            }else{
              q.push(nums1[i]) ;
                i++;
            }
        }
        for(;i<m;i++){
         q.push(nums1[i]) ;   
        }
        for(;j<n;j++){
         q.push(nums2[j]);   
        }
        
        int M=0;
        while(!q.empty()){
         nums1[M++] = q.front();
            q.pop();
        }
    }
};
