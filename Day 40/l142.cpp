class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
     ListNode *slow=head , *fast=head;
        if(!head){
            return NULL;
        }
      while(fast!=NULL && fast->next!=NULL){
          slow=slow->next;
          fast=fast->next->next;
          if(slow==fast){
              break;
          }
      }
        if(fast==NULL || fast->next==NULL){
            return NULL;
        }else{
            fast = head;
            while(fast!=slow){
                fast=fast->next;
                slow=slow->next;
            }
        }
        return slow;
    }
};
