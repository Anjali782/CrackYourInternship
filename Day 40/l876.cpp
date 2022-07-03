class Solution {
public:
    ListNode* middleNode(ListNode* head) {
     ListNode* p = head;
        int count=0;
        if(p->next==NULL){
            return p;
        }
       while(p->next!=NULL){
        count++; 
           p=p->next;
       }
        if(count%2==0){
            count--;
        }
        p=head;
        int i=0;
       while(i< count/2 +1){
         p= p->next;
           i++;
       }
        return p;
    }
};
