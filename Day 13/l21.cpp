class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       ListNode *p, *q,*ans,*t;
        p= list1;
        q= list2;
        if (p == NULL) {
            return q;
        }
        if (q == NULL) {
            return p;
        }
        
        if(p->val < q->val){
               ans=t=p;
            p= p->next;
            t->next=NULL;
            }else{
               ans=t=q;
            q= q->next;
             t->next=NULL;
            }
        while(p != nullptr && q!=nullptr){
           if(p->val < q->val){
              t->next =p;
               t=p;
               p=p->next;
                t->next=NULL;
            }else{
              t->next =q;
               t=q;
               q=q->next;
                t->next=NULL;
            } 
        }
        
       while(p!= nullptr){
           t->next =p;
               t=p;
               p=p->next;
            t->next=NULL;
       } 
        
         while(q != nullptr){
           t->next =q;
               t=q;
               q=q->next;
              t->next=NULL;
       }
        
        return ans;
        
    }
};
