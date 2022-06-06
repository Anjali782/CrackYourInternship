class Solution {
public:
    ListNode* reverse(ListNode* root) {
        if (root == NULL || root->next == NULL) {
            return root;
        }
        
        ListNode* small = reverse(root->next);
        ListNode* tail = root->next;
        
        tail->next = root;
        root->next = NULL;
        
        return small;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        int carry = 0;
        
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        while(l1 != NULL || l2 != NULL || carry) {
            int sum = 0;
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            sum += carry;
            carry = sum / 10;
            ListNode* test = new ListNode(sum % 10);
            temp->next = test;
            temp = temp->next;
        }
        
        ListNode* v = reverse(ans->next);
        return v;
    }
};
