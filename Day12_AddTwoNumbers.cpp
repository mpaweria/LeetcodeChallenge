class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;

        while(l1 || l2 || carry) {
            int sum = 0;

            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            if(carry)
                sum += carry;

            ans->next = new ListNode(sum % 10);
            ans = ans->next;
            carry = sum / 10;
        }
        return dummy->next;
    }
};