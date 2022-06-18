class Solution {
public:
    Node* connect(Node* root) {
       if(!root){
           return NULL;
       }
       queue<Node*>q;
       q.push(root);
        
       while(!q.empty()){
           Node*temp=new Node(0);
           Node* curr=temp;
           int size=q.size();
           for(int i=0;i<size;i++){
               auto node=q.front();
               q.pop();
               curr->next=node;
               curr=curr->next;
               
               if(node->left){
                   q.push(node->left);
               }if(node->right){
                   q.push(node->right);
               }
           }
           temp->next=NULL;
           delete temp;
           
           curr->next=NULL;
       }
       return root; 
    }
};


           
  
