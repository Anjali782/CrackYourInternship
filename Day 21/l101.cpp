class Solution {
public:
    vector<int> v;
    
    vector<int> inorder(TreeNode* root){
        if(root){
       inorder(root->left); 
         v.push_back(root->val);
       inorder(root->right);     
       }
        return v;
    }
    
    int lroot(TreeNode* p){
        int l=0;
        if (p != nullptr){
        l = lroot(p->left);
        return l+1;
        }
        return 0;
    }
    
    int rroot(TreeNode* p){
        int r=0;
        if (p != nullptr){
        r = rroot(p->right);
        return r+1;
        }  
        return 0;
    }
    
    bool isSymmetric(TreeNode* root) {
   
    
        vector<int> v1;
        v1=inorder(root);
        int j=v1.size();
            
        for(int i=0;i<j/2;i++){
         if(v[i] == v[j-1-i] && lroot(root) == rroot(root))
             continue;
         else
            return false;   
        }
        return true;
    }
};
