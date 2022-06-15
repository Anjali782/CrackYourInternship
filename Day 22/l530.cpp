class Solution {
    int prev = 1e5;
    void inorder(TreeNode* root,int &mindiff){
        if(!root) return;
        if(root){
            inorder(root->left,mindiff);
            if(abs(prev - root->val) < mindiff){
                mindiff = abs(prev - root->val);
            }
            prev = root->val;
            inorder(root->right,mindiff);
        }
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int mindiff = INT_MAX;
        inorder(root,mindiff);
        return mindiff;
    }
};
