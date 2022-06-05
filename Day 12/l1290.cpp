class Solution {
public:
	int getDecimalValue(ListNode* head) {
		int ans = head->val;
		while(head->next != NULL){
			ans = ans*2 + head->next->val;
			head = head->next;
		}
		return ans;
	}
};
