class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
     vector<int>v;
      if(root==NULL){
          return v;
      }   
     queue<TreeNode*>q;
      q.push(root);
      while(!q.empty()){
       v.push_back(q.front()->val);
       int size=q.size();
          while(size--){
           auto curr = q.front(); q.pop();
            if(curr->right) q.push(curr->right);
            if(curr->left) q.push(curr->left);   
          }
      }  
       return v;
    }
};
