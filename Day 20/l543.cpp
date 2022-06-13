class Solution {
public:
    int solve(TreeNode* root , int &res){
        if(root==nullptr){
            return 0;
        }
        int l=solve(root->left , res);
        int r=solve(root->right , res);
        int temp= max(l,r)+1;
        int ans=max(temp,1+l+r);//comparing result when including root node and when not including root
        res=max(res,ans);
        
        return temp;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
    int res=INT_MIN;
        solve(root,res);
        return res-1;
    }
};
