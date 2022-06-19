class Solution {
public:
    vector<vector<int>>v;
    void level(TreeNode* root , int x){
        if(!root){
          return;   
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            
            int size=q.size();
            vector<int>v1(size);
            
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                
                int index = (x%2!=0 ? i : size - 1 - i);
				v1[index] = temp->val;
                
                  if(temp->left){
                        q.push(temp->left);
                   }if(temp->right){
                        q.push(temp->right);
                   }  
              }
           x++; 
           v.push_back(v1); 
        }
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      level(root,1); 
        return v;
    }
};
