class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL || head->next==NULL){
            return head;
        }
        bool j = false;
        while (head->next!=NULL && head->val == head->next->val){
            j = true;
            head->next = head->next->next;
        }
        if (j){
            head = deleteDuplicates(head->next);
            return head;
        }
        head->next = deleteDuplicates(head->next);
        return head;
    }
};
