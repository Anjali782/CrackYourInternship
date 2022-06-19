class Solution {
public:
    vector<int>v;
    void inorder(TreeNode* p){
        if(p){
        inorder(p->left);
        v.push_back(p->val);
        inorder(p->right);}
    }
    
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        int count =-1;
        while(k--){
         count++;
        }
        return v[count];
    }
};
