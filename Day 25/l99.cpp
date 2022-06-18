class Solution {
public:
    vector<int>v;
    void inorder(TreeNode* p){
     if(p){   
     inorder(p->left);
     v.push_back(p->val);
     inorder(p->right);}   
    }
    void recoverTree(TreeNode* root) {
     inorder(root);
        int i=1;
        for(i=1;i<v.size();i++){
            if(v[i-1]>v[i]){
                break;
            }
        }
        int a=v[i-1];
        int index=i-1;
        
        for(;i<v.size() ;i++){
          if(a>v[i]){
              continue;
          } else{
             int k =v[i];
              v[i]=a;
              v[index]=k;
          } 
        }
        if(i+1==v.size()){
           int size=v.size();
            v[index] = v[size-1];
            v[size-1]=a;
        }
    }
};
