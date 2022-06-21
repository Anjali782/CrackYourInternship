int counNodes(struct Node *root)
{
    struct Node *current, *pre;
    int count = 0;
    if (root == NULL)
        return count;
    current = root;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            count++;
            current = current->right;
        }
        else
        {
            pre = current->left;
 
            while (pre->right != NULL &&
                   pre->right != current)
                pre = pre->right;
            if(pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
            else
            {
                pre->right = NULL;
                count++;
                current = current->right;
            } 
        }
    } 
    return count;
}
 
int findMedian(struct Node *root)
{
   if (root == NULL)
        return 0;
 
    int count = counNodes(root);
    int currCount = 0;
    struct Node *current = root, *pre, *prev;
 
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            currCount++;
            if (count % 2 != 0 && currCount == (count+1)/2)
                return prev->data;
            else if (count % 2 == 0 && currCount == (count/2)+1)
                return (prev->data + current->data)/2;
            prev = current;
            current = current->right;
        }
        else
        {
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;
            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
            else
            {
                pre->right = NULL;
 
                prev = pre;
                currCount++;
                if (count % 2 != 0 && currCount == (count+1)/2 )
                    return current->data;
 
                else if (count%2==0 && currCount == (count/2)+1)
                    return (prev->data+current->data)/2;
                prev = current;
                current = current->right;
 
            } 
        }
    }
}
 /**
 int counNodes(struct Node *root )
{
  int count=0;    
  if(!root){
      return 0;
  }
  if(root){
  counNodes(root->left);
  count++;
  counNodes(root->right);
  }
  return count;
	
}
**/

/* Function to find median in O(n) time and O(1) space
using Morris Inorder traversal*/
/**
int findMedian(struct Node *root)
{
if (root == NULL)
		return 0;
 int count= counNodes(root);
 if(count%2!=0){
     int n=count/2 + 1;
     
     if(root){
      findMedian(root->left);
      n--;
      if(n==0){
         return root->data;
      }
      findMedian(root->right);
  }
     return root->data;
 }
}**/

