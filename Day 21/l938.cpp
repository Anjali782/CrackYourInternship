class Solution {
public:
    void sumbst(TreeNode* root, int low, int high , int &sum){
     if(!root){
      return;   
     }
      if(root->val <= high && root->val >= low){
          sum += root->val;
      }
       if(root->val <low){
        sumbst(root->right , low , high , sum);    
       }
       else if(root->val >high){
        sumbst(root->left , low , high , sum);    
       }
       else{ 
       sumbst(root->left , low , high , sum);
       sumbst(root->right , low , high , sum);
       }     
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum =0; 
      sumbst(root , low , high , sum);
        return sum;
    }
};
