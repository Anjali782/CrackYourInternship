class Solution {
public:
 
   int inorder(TreeNode* p,int &ans){
        if(p==NULL){
        return 0;}
     if(p->left!=NULL && p->left->left==NULL && p->left->right==NULL){
      ans=ans+p->left->val;
   }
       inorder(p->left,ans);
       inorder(p->right,ans);
       return ans;
  }  
    int sumOfLeftLeaves(TreeNode* root) {
        int valu=0;
        int ans =inorder(root,valu);
        return  ans;
    }
};
