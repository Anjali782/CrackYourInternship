class Solution {
public:
    vector<int> preorder(Node* root) {
     vector<int>ans;
      if(!root){
         return ans;
       }  
        stack<Node*>st;
        st.push(root);
        
        while(!st.empty()){
            Node*temp=st.top();
            st.pop();
            ans.push_back(temp->val);
            for(auto it = temp->children.rbegin();it!=temp->children.rend();it++){
                st.push(*it);
            }
        }
        return ans;
    }
};
