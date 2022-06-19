Node* creat(int pre[] , int &i , int h , int size){
    if(i>=size || h < pre[i]){
        return NULL;
    }
    Node *root= newNode(pre[i++]);
    root->left= creat(pre , i, root->data ,size);
    root->right= creat(pre , i, h ,size);
    
    return root;
}


Node* post_order(int pre[], int size)
{
    if(!size){
        return NULL;
    }
    int i=0;
    Node *root=creat(pre , i , INT_MAX, size);
    return root;
}
