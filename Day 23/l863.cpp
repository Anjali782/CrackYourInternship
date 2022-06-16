class Solution {
public:
    void markParent(TreeNode *root , unordered_map<TreeNode *,TreeNode *>&markP , TreeNode *target){
     queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *curr=q.front();
            q.pop();
            if(curr->left){
                markP[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                markP[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
     unordered_map<TreeNode *,TreeNode *>markP;
        markParent(root,markP,target);
        
        unordered_map<TreeNode *,bool>visited;
        queue<TreeNode *>q;
        
        q.push(target);
        visited[target]=true;
        
        int dist=0;
        
        while(!q.empty()){
           int size=q.size();
           if(dist++ == k){
               break;
           }
           for(int i=0;i<size;i++){
               TreeNode* curr=q.front();
               q.pop();
               if(curr->left && !visited[curr->left]){
                   q.push(curr->left);
                   visited[curr->left]=true;
               }
               if(curr->right && !visited[curr->right]){
                   q.push(curr->right);
                   visited[curr->right]=true;
               }
               if(markP[curr] && !visited[markP[curr]]){
                   q.push(markP[curr]);
                   visited[markP[curr]]=true;
               }
           } 
        }
        vector<int>result;
        while(!q.empty()){
            TreeNode*temp=q.front();
            q.pop();
            result.push_back(temp->val);
        }
        return result;
    }
};
