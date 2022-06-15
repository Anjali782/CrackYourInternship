class Solution {
public:
    
    int height(TreeNode* root){
        int l=0;
        int r=0;
        if(root){
            l = height(root->left);
            r= height(root->right);
        }if(l>r)
            return l+1;
        else
            return r+1;
    }
    bool isBalanced(TreeNode* root) {
        
        if(root==NULL) 
            return true;
        
        int l = height(root->left);  
        int r = height(root->right); 
        
        return (abs(l-r)<=1) && isBalanced(root->left) && isBalanced(root->right); // checking
        
    }
};
