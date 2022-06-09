class Solution {
public:
    ListNode*rev(ListNode*head, ListNode*now , ListNode *newNode){
        ListNode*temp;
        while(head!=now){
         temp= head->next;
         head->next=newNode;
         newNode=head;
         head=temp;   
        }   
       head->next=newNode;
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
     if (k==1){
            return head;
        }
        int i=1;
        ListNode* now = head;
        while (now!=NULL && i<k){
            now=now->next;
            i++;
        }
        if (now==NULL){
            return head;
        }
        return rev(head, now, reverseKGroup(now->next,k));
    }
};
