
class Solution {
public:
    
    void TreePaths(TreeNode* root, string path, vector<string> &ans)
    {
        if(root==NULL)
        {
            return;
        }
        
        if(root->left==NULL && root->right==NULL)
        {
            path += to_string(root->val);
            ans.push_back(path);
            return;
            
        }
        path += (to_string(root->val)) + "->";
        TreePaths(root->left,path,ans);
        TreePaths(root->right,path,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> ans;
        TreePaths(root,"", ans);
        
        return ans;
        
    }
};
