class Solution {
public:
    vector<TreeNode*>v;
    
    void pre(TreeNode*root){
        if(root){
         v.push_back(root);   
         pre(root->left);
         pre(root->right);   
        }
    }
    void flatten(TreeNode* root) {
      if(!root){
          return;
      }  
     pre(root);
      for(int i=0;i<v.size()-1;i++){
          v[i]->left=NULL;
          v[i]->right=v[i+1];
      } 
    }
};
