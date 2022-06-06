class Solution {
public:
    ListNode * reverseList(ListNode * head){
        ListNode * current = head;
        ListNode * previous = NULL;
        while(current !=NULL){
            ListNode * next = current->next;
            current->next = previous;
            previous = current ;
            current =next;
        }
        return previous;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL){
            return true;
        }
       
        int size = 0 ;
        ListNode* slow = head;
        ListNode* fast = head ;
        while(fast->next != NULL && fast->next->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode * temp = reverseList(slow->next);
        
        ListNode * start = head;
        while(temp!=NULL){
            if(temp->val != start->val){
                return false;
            }
            temp = temp->next;
            start = start->next;
        }
        return true;
    }
};
