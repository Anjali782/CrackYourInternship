Info largestBSTBT(Node* root)
{
    if (root == NULL)
        return {0, INT_MIN, INT_MAX, 0, true};
    if (root->left == NULL && root->right == NULL)
        return {1, root->data, root->data, 1, true};

    Info l = largestBSTBT(root->left);
    Info r = largestBSTBT(root->right);
    Info ret;
    ret.sz = (1 + l.sz + r.sz);
    if (l.isBST && r.isBST && l.max < root->data && r.min > root->data)
    {
        ret.min = min(l.min, min(r.min, root->data));
        ret.max = max(r.max, max(l.max, root->data));
        ret.ans = max(l.ans, r.ans) + 1;
        ret.isBST = true;
        return ret;
    }
    ret.ans = max(l.ans, r.ans);
    ret.isBST = false;
 
    return ret;
}
