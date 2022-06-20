class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(root==nullptr){
            return s;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            
            if(curr==nullptr){
                s.append("#,");
            }
            else{
                s.append(to_string(curr->val)+",");
            }
            
            if(curr!=nullptr){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){
            return nullptr;
        }
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            
            getline(s,str,',');
            if(str=="#"){
                curr->left=nullptr;
            }
            else {
                TreeNode* leftNode=new TreeNode(stoi(str));
                curr->left=leftNode;
                q.push(leftNode);
            }
            
            getline(s,str,',');
            if(str=="#"){
                curr->right=nullptr;
            }
            else {
                TreeNode* rightNode=new TreeNode(stoi(str));
                curr->right=rightNode;
                q.push(rightNode);
            }
   
        }
        return root;
    }
};
