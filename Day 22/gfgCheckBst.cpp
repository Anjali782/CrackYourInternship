vector<int>v;
void inorder(Node*root){
    if(root){
      inorder(root->left);
      v.push_back(root->data);
      inorder(root->right);
    }
}
bool isDeadEnd(Node *root)
{
  inorder(root);
  int flag=0;
  for(int i=1;i<v.size();i++){
   if(v[i]>=v[i-1]){
       continue;
   }else{
       flag=1;
       break;
   }   
  }
  if(flag==1){
      return false;
  }
  return true;
}
