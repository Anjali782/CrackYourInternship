class Solution {
public:
    int Sum(TreeNode* root , int &sum){
        if(root==NULL){
            return 0;
        }
        int l=Sum(root->left , sum);
        int r=Sum(root->right , sum);
        int temp = max(max(l,r)+root->val , root->val);
       
        int ans = max(temp , l+r+root->val);
        sum = max(sum , ans);
        
       return temp; 
    }
    int maxPathSum(TreeNode* root) {
      int sum = INT_MIN;  
      Sum(root , sum); 
        return sum;
    }
};
