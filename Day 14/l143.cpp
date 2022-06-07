class Solution {
public:
  ListNode* reverse(ListNode* pre, ListNode* curr,ListNode* nxt)
    {
        while(curr)
        {
            nxt=curr->next;
            curr->next = pre;
            pre = curr;
            curr = nxt;
        }
        return pre;
    }
    void reorderList(ListNode* head) {
        // if link-list is empty or having only one or two node then we have nothing to do. so simply return 
        if(!head or !head->next or !head->next->next)
         return ;
        
        //finding mid of link-list
        ListNode* slow= head, *fast=head;
        while(fast and fast->next)
        {
            slow=slow->next;
            fast= fast->next->next;
        }
       
        ListNode* pre = slow , *curr = slow->next; 
        // break the link from middle
        pre->next = NULL;  fast = head;
        
        // reverse the link-list after mid point
        slow = reverse(pre,curr,NULL);
        
        //insert the node of reverse link in first half alternatively 
        while(fast->next and slow->next)
        {
            ListNode* temp1 = fast->next;
            ListNode* temp2 = slow->next;
            fast->next = slow;
            slow->next=temp1;
            slow=temp2;
            fast=temp1;
            
        }
    }
};
