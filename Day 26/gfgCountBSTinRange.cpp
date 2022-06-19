class Solution{
public:
    void len(Node *root , int l , int h , int &res){
        if(root==NULL){
            return ;
        }
      
        if(l<= root->data and root->data <= h)
           res++ ; 
      
         res += getCount(root->left,l,h) ; 
         res += getCount(root->right,l,h) ;
        
        return ;  
    }

    int getCount(Node *root, int l, int h)
    {
      if(!root){
          return 0;
      }
     int ans=0; 
     len(root , l , h , ans);
     return ans;
    }
};
