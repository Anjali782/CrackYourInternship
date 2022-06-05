class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * p=head , *q=head;
    
        while(q!=NULL && q->next !=NULL){
          p= p->next;
          q = q->next->next; 
            if(p == q)
                return true;
        }
      return false;
    }
};
