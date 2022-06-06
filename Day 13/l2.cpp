class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        
        ListNode *c,*root,*t;
        
        ListNode *a=l1,*b=l2, *d;
        int carry =0;
        int len1=0,len2=0;
        
         while(a!=NULL || b!= NULL){
             if(a){
                 len1++;
                 a=a->next;
             } if(b){
                 len2++;
                 b=b->next;
             }
         }
        if(len1>len2){
            swap(l1 , l2);
        }
        
        while (len1<len2)
        {
            d=new ListNode;
            d->val =0;
            d->next=NULL;
            a=d;
            a=a->next;
            len1++;
        }
            int sum = l1->val + l2->val+carry;
            int rem = sum%10;
            c = new ListNode;
            c->val = rem;
            c->next = NULL;
            carry= sum/10;
            l1= l1->next;
            l2=l2->next;
            t= root = c;
        
        while(l1 && l2){
            int sum = l1->val + l2->val+carry;
            int rem = sum%10;
            c = new ListNode;
            c->val = rem;
            c->next = NULL;
            t->next =c;
            t=t->next;
            carry= sum/10;
            l1= l1->next;
            l2=l2->next;
        }
        while(l1){
            int sum = l1->val+carry;
            int rem = sum%10;
            c = new ListNode;
            c->val = rem;
            c->next = NULL;
            t->next =c;
            t=t->next;
            carry= sum/10;
            l1= l1->next;
            
        }
        while(l2){
            int sum = l2->val+carry;
            int rem = sum%10;
            c = new ListNode;
            c->val = rem;
            c->next = NULL;
            t->next =c;
            t=t->next;
            carry= sum/10;
            l2= l2->next;
            
        }
        if (carry)
        {
            c = new ListNode;
            c->val = carry;
            c->next = NULL;
            t->next =c;
            t=t->next;
        }
        return root;
    }
};
