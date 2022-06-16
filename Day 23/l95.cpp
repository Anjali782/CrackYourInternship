class Solution {
public:
    vector<TreeNode*>helper(int start , int end){
        vector<TreeNode*>trees;
        if(start>end){
          trees.push_back(NULL);  
        }
        for(int i=start ;i<=end;i++){
            vector<TreeNode*>leftsub =helper(start , i-1);
            vector<TreeNode*>rightsub =helper(i+1 , end);
            
            for(auto l : leftsub){
              for(auto r : rightsub){
                TreeNode* temp = new TreeNode(i, l, r);
                 trees.push_back(temp);
                }
            }
        }
        return trees;
    }
    vector<TreeNode*> generateTrees(int n) {
      return helper(1,n);  
    }
};
