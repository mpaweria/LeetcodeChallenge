class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)return nullptr;
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr){
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
};