class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* root=new TreeNode();
        if(!root1){
            return root2;
        }
        if(!root2){
            return root1;
        }
        root->val=root1->val+root2->val;
        root->left=mergeTrees(root1->left,root2->left);
        root->right=mergeTrees(root1->right,root2->right);
        
        return root;
    }
};
