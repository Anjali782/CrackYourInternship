class Solution {
public:
    int maxDepth(TreeNode* root) {
      int l=0;
        int r=0;
        if(root!=nullptr){
          l= maxDepth(root->left);
          r= maxDepth(root->right);
            
            if(l>r){
                return l+1;
            }else{
                return r+1;
            }
        }
        return 0;
    }
};
