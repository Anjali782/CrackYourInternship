class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      //if root is null else p or q is equal to root then root only is the common ancestor  
     if(!root || root==p || root==q){
         return root;
     }
        //we will go on left first and then right
     TreeNode * Left= lowestCommonAncestor(root->left,p,q);
     TreeNode * Right= lowestCommonAncestor(root->right,p,q); 
       
        //if from left and right the are returning somthing mean they gote the p and q to that root is the common              ancestor
        if(Left && Right){
            return root;
        }
        //like in this case we will find 5 then we don't go left and right og node 5 will return 5 from there mean at          3 from left you will find 3  and from right 1 so left right both returning somthing not null at some node so          that node only the lca
        else if(Left){
            return Left;
        }else{
            return Right;
        }
    }
};
