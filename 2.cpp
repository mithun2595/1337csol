/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* n = head;
        int carry = 0;
        int n1, n2;
        while(l1 || l2 || carry) {
            n1 = n2 = 0;
            if(l1) {
                n1 = l1->val;
                l1 = l1->next;
            }
            if(l2) {
                n2 = l2->val;
                l2 = l2->next;
            }
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            int val = sum % 10;
            n->next = new ListNode(val);
            n = n->next;
        }
        return head->next;
    }
};