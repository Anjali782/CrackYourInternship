class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      ListNode *A=headA;
      ListNode *B=headB; 
      
      while(A){
          while(B){
              if(A->next == B->next){
                  return A->next;
              }else{
                  B= B->next;
              }
          }
          A = A->next;
      }
        return NULL;
    }
};
