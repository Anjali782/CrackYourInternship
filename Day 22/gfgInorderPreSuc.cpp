void findPreSuc(Node* temp, Node*& pre, Node*& suc, int key)
{
Node* root=temp;
while(root){
           if(key>=root->key){
               root=root->right;
           }else{
               suc=root;
               root=root->left;
           }
       }
       root=temp;
       
        while(root){
           if(key>root->key){
               pre=root;
               root=root->right;
           }else{
               root=root->left;
           }
       }
}
