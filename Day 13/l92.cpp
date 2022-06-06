class Solution {
  public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
   vector<int>v;
   int j=0;
   ListNode* temp=head;
      
   while(temp!=NULL){
   v.push_back(temp->val);
   temp=temp->next;
   }
   reverse(v.begin()+left-1,v.begin()+right);
   
       ListNode* temp1=head;
       while(temp1!=NULL){
           temp1->val=v[j];
           j++;
           temp1=temp1->next; 
       }
     return head;
  }
};
