class Solution {
public:
    ListNode* sortList(ListNode* head) {
     vector<int>v;
     ListNode *curr =head , *temp=head;
      while(curr!=NULL){
          v.push_back(curr->val);
          curr=curr->next;
      }
      sort(v.begin() , v.end());
       int i=0; 
      while(temp!=NULL){
          temp->val=v[i++];
          temp=temp->next;
      }  
        return head;
    }
};
