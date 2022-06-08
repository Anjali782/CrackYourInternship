class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* p= head , * prev= head; ;
       
     int count=0;
        
        if(p->next==NULL && n==1){
            return NULL;
        }
        while(p->next!=NULL){
            count++;
            p=p->next;
        }
        count++;
        if(count==n){
         return head->next;  
        }
        
        p=head;
        prev= head;
        int loop = count-n;
        
       while(loop--){
        prev=p;
        p=p->next;   
       } 
        prev->next=p->next;
        return head;
    }
};
