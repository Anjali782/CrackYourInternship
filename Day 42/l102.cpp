class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>>v;
        if(!root){
            return v;
        }
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
          int size=q.size();
           vector<int>v2;
        while(size--){
           auto curr = q.front();
            v2.push_back(curr->val);
            q.pop();
            if(curr->left) 
                q.push(curr->left);
            if(curr->right) 
                q.push(curr->right);
         
            if(size==0){
                v.push_back(v2);
            }
          }
        }
        return v;
    }
};
