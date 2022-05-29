class Solution {
public:
    
    void permutation(vector<vector<int>>&ans , vector<int>&result , int i ,int k ,int n){
        if(k==0){
            ans.push_back(result);
            return;
        }
        if(i>n){
            return;
        }
        result.push_back(i);
       permutation(ans , result, i+1, k-1, n);
        result.pop_back();
        permutation(ans, result, i+1, k, n);
    }
    
    vector<vector<int>> combine(int n, int k) {
     vector<vector<int>> ans;
     vector<int> result ;
     permutation(ans , result , 1 , k ,n);
        return ans;
    }
};
