class Solution{
    public:
    
    int findlevel(Node*root , int x , int level){
        if(!root){
            return -1;
        }
         if(root->data == x){
            return level;
        }
        int left=findlevel(root->left , x , level+1);
        if(left==-1){
            return findlevel(root->right,x,level+1);
        }
        return left;
    }
    
    Node* LCA(Node* root , int a , int b){
      if(root==NULL){
          return NULL;
      }
      if(root->data==a || root->data==b){
          return root;
      }
        Node* left = LCA(root->left, a, b);
        Node* right = LCA(root->right, a, b);
        if(left == NULL){
            return right;
        }
        if(right == NULL){
            return left;
        }
        return root;
    }
    
    int findDist(Node* root, int a, int b) {
        if(root==NULL){
            return -1;
        }
        if(a==b){
            return 0;
        }
        Node*lca=LCA(root , a , b);
        int d1=findlevel(lca,a,0);
        int d2=findlevel(lca,b,0);
        
        return d1+d2;
    }
};
