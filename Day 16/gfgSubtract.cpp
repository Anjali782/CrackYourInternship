 Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
int getLength(Node* Node)
{
    int size = 0;
    while (Node != NULL) {
        Node = Node->next;
        size++;
    }
    return size;
}
Node* paddZeros(Node* sNode, int diff)
{
    if (sNode == NULL)
        return NULL;
 
    Node* zHead = newNode(0);
    diff--;
    Node* temp = zHead;
    while (diff--) {
        temp->next = newNode(0);
        temp = temp->next;
    }
    temp->next = sNode;
    return zHead;
}
Node* subtractLinkedListHelper(Node* l1, Node* l2, bool& borrow)
{
    if (l1 == NULL && l2 == NULL && borrow == 0)
        return NULL;
 
    Node* previous = subtractLinkedListHelper( l1 ? l1->next : NULL, l2 ? l2->next : NULL, borrow);
 
    int d1 = l1->data;
    int d2 = l2->data;
    int sub = 0;
    if (borrow) {
        d1--;
        borrow = false;
    }
    if (d1 < d2) {
        borrow = true;
        d1 = d1 + 10;
    }
    sub = d1 - d2;
    Node* current = newNode(sub);
    current->next = previous;
    return current;
}
Node* subtractLinkedList(Node* l1, Node* l2)
{
    if (l1 == NULL && l2 == NULL){ 
       return NULL;
      }
    int len1 = getLength(l1);
    int len2 = getLength(l2);
 
    Node *lNode = NULL, *sNode = NULL;
 
    Node* temp1 = l1;
    Node* temp2 = l2;
    if (len1 != len2) {
        lNode = len1 > len2 ? l1 : l2;
        sNode = len1 > len2 ? l2 : l1;
        sNode = paddZeros(sNode, abs(len1 - len2));
    }
    else {
        while (l1 && l2) {
            if (l1->data != l2->data) {
                lNode = l1->data > l2->data ? temp1 : temp2;
                sNode = l1->data > l2->data ? temp2 : temp1;
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    if(lNode==NULL&&sNode==NULL)
    {
      return newNode(0);
    }
    bool borrow = false;
    return subtractLinkedListHelper(lNode, sNode, borrow);
}
 
