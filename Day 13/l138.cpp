class Solution {
public:
   Node* copyRandomList(Node* head) {//creating new nodes and putting them between given linked list for mapping
    Node *itr=head, *front=head;
    while(itr!=NULL){
        front = itr->next;
        Node* copy = new Node(itr->val);
        itr->next = copy;
        copy->next = front;
        itr = front;    
    }
    itr = head;
    while(itr!=NULL){//linking random pointers with help of old nodes
        if(itr->random!=NULL)
            itr->next->random = itr->random->next;
        itr = itr->next->next;
    }
    itr=head;
    Node* newhead = new Node(0); //breaking the mapped links and saperate them
    Node* temp = newhead;
    while(itr!=NULL){
        front = itr->next->next;
        temp->next = itr->next;
        itr->next = front;
        temp = temp->next;
        itr = itr->next;
    }
    return newhead->next;
 }
};


