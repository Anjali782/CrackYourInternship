
class Solution {
public:
    bool check(TreeNode* root ,TreeNode* subRoot){
     if(root && subRoot){
       if(root->val == subRoot->val){
         return check(root->left,subRoot->left) && check(root->right,subRoot->right);  
       }
         return false;
     }
        if(root || subRoot){
            return false;
        }
        return true;
    }
        
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
      if(root){
          if(check(root , subRoot)){
              return true;
          }
        return isSubtree(root->left , subRoot) || isSubtree(root->right , subRoot);
      }
        return false;
    }
};
