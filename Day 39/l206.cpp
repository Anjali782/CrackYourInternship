class Solution {
public:
    ListNode* reverseList(ListNode* head) {
     ListNode * current = head;
     ListNode * prev = NULL;
        while(current!=NULL){
            ListNode* next = current->next;
            current->next= prev;
            prev=current;
            current=next;
        }
        return prev;
    }
};
