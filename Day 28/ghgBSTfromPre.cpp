node* constructTreeUtil(int pre[], int* preIndex, int low, int high, int size)
{
    if (*preIndex >= size || low > high)
        return NULL;
    node* root = newNode(pre[*preIndex]);
    *preIndex = *preIndex + 1;
    if (low == high)
        return root;
    int i;
    for (i = low; i <= high; ++i)
        if (pre[i] > root->data){
         break;
        }
    root->left = constructTreeUtil(pre, preIndex, *preIndex, i - 1, size);
    root->right = constructTreeUtil(pre, preIndex, i, high, size);
    return root;
}

node* constructTree(int pre[], int size)
{
    int preIndex = 0;
    return constructTreeUtil(pre, &preIndex, 0, size - 1,size);
}
 
