class Solution {
public:
    void reverse(TreeNode* root){
        if(!root){
            return;
        }
        TreeNode*temp = root->left;
        root->left=root->right;
        root->right=temp;
        
        reverse(root->left);
        reverse(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        reverse(root);
        return root;     
    }
};  
