class Solution {
public:
   int findsum(TreeNode*root , long long int sum){
       if(root==NULL){
        return 0;  
       }
       long long int res=0;
       if(root->val == sum)
       {
           res++;
       }
    
       res += findsum(root->left , sum - root->val);
       res += findsum(root->right , sum - root->val);
       
       return res;
   }
   int pathSum(TreeNode* root, int targetSum) {
    if(root == NULL){
        return 0;
    }
     return pathSum(root->left , targetSum) + findsum(root , targetSum) + pathSum(root->right , targetSum); 
   }
};
