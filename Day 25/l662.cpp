class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        int ans=0;
        queue<pair<TreeNode* , int>>q;
        q.push({root , 0});
        while(!q.empty()){
            int size=q.size();
            int minm=q.front().second;
            int first , last;
            for(int i=0;i<size;i++){
                long long int curr = q.front().second-minm;//(1,1-1)=>left=(3 , 0*2+1)=>right=(2 , 0*2+2), so                                                                  that there is no overflow of memory
                TreeNode* temp=q.front().first;
                q.pop();
                
                if(i==0){
                    first = curr;
                }if(i==size-1){
                    last = curr;
                }
                if(temp->left){
                    q.push({temp->left , curr*2+1});
                } if(temp->right){
                    q.push({temp->right , curr*2+2});
                }
            }
            ans = max(ans , last-first+1);
        }
        return ans;
    }
};
