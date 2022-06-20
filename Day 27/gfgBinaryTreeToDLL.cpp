class Solution
{
    public:
    vector<Node*>v;
    
    void inorder(Node*root){
        if(root){
            inorder(root->left);
            v.push_back(root);
            inorder(root->right);
        }
    }
    Node * bToDLL(Node *root)
    {
      if(!root){
          return NULL;
      }
      inorder(root);
      for(int i=0;i<v.size()-1;i++){
        v[i]->right=v[i+1];
        v[i+1]->left=v[i];
      }
      int size=v.size();
      v[size-1]->right=NULL;
      return v[0];
    }
};
