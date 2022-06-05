class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode *t,*p;
        t=head;
        
        if(t==NULL)
            return t;
        
         p=head->next;
        
        if(p==NULL)
            return head;
        
        while(p!= NULL){
         if(t->val == p->val){
             p=p->next;
             t->next = p;
         }else{
            t=p;
            p=p->next;}
        }
        
        return head;
    }
};
