class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
     TreeNode *lca;
        while(true){
            int value=root->val;
            if(value > p->val && value > q->val){
                root=root->left;
            }else if(value < p->val && value < q->val){
                root=root->right;
            }else{
                lca=root;
                break;
            }
        }
        return lca;
    }
};
