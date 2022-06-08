void segregateEvenOdd(struct Node **head_ref)
{
    Node *evenStart = NULL;
    Node *evenEnd = NULL;
    Node *oddStart = NULL;
    Node *oddEnd = NULL;

    Node *currNode = *head_ref;
     
    while(currNode != NULL){
        int val = currNode -> data;
        if(val % 2 == 0) {
            if(evenStart == NULL){
                evenStart = currNode;
                evenEnd = evenStart;
            }
        
            else{
                evenEnd -> next = currNode;
                evenEnd = evenEnd -> next;
            }
        }
        else{
            if(oddStart == NULL){
                oddStart = currNode;
                oddEnd = oddStart;
            }
            else{
                oddEnd -> next = currNode;
                oddEnd = oddEnd -> next;
            }
        }
        currNode = currNode -> next;   
    }
    if(oddStart == NULL || evenStart == NULL){
        return;
    }  
    evenEnd -> next = oddStart;
    oddEnd -> next = NULL;
    *head_ref = evenStart;
}
