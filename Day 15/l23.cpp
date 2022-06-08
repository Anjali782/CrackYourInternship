class Solution {
    ListNode* merge2lists(ListNode* l1 , ListNode* l2) {
        ListNode* dummyhead = new ListNode(-1) ; 
        ListNode *temp = dummyhead ; 
        while (l1 && l2) {
            if (l1->val < l2->val) {
                temp -> next = l1 ;
                temp = temp -> next ; 
                l1 = l1 -> next ; 
            }
            else {
                temp -> next = l2 ;
                temp = temp -> next ; 
                l2 = l2 -> next ;
            }
        }
        if (l1){
            temp -> next = l1 ;
        }
        if (l2){
            temp -> next = l2 ;
        }
        return dummyhead -> next ; 
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()){
            return NULL ;
        }
        int ind = lists.size()-1 ; 
        while (ind > 0) {
            lists[ind-1] = merge2lists(lists[ind] , lists[ind-1]) ;
            ind-- ; 
        }
        return lists[0] ;
    }
};
