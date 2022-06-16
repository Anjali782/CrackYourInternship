class Solution {
private:
    bool travel(TreeNode* root,long min,long max){
        if(!root)
            return true;
        
        if(root->val>min and root->val<max)
            return travel(root->left,min,root->val) and travel(root->right,root->val,max);
         
        return false;
    }
public:
    bool isValidBST(TreeNode* root) {
        return travel(root,LONG_MIN,LONG_MAX);
    }
};
