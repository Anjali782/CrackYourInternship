class BSTIterator {
public:
    vector<int>v;
    int i=0;
    
    void inorder(TreeNode* root){
      if(root){
       inorder(root->left);
       v.push_back(root->val);
       inorder(root->right);   
      }  
    }
    
    BSTIterator(TreeNode* root) {
    inorder(root);
    }
    
    int next() {
     if(i<v.size()){
         i++;
         return v[i-1];
     }return -1; 
    }
    
    bool hasNext() {
     if(i<v.size()){
         return true;
     }
        return false;
    }
};
