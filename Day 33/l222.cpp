class Solution {
public:
    int lheight(TreeNode* root){
        int h=0;
        while(root){
            h++;
            root=root->left;
        }
        return h;
    }
    int rheight(TreeNode* root){
        int h=0;
        while(root){
            h++;
            root=root->right;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
     if(!root){
         return 0;
     }
     int lh=lheight(root);
     int rh=rheight(root);
        if(lh==rh){
            return (1<<lh)-1;
        }
      return 1+countNodes(root->left)+countNodes(root->right);  
    }
};
