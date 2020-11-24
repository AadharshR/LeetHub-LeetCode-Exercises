/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        
        ListNode* t3 = new ListNode(0);
        ListNode* head = t3;
        while (t1 || t2  ) {
            int t1Val = (t1 == NULL) ? 0 : t1->val;
            int t2Val = (t2 == NULL) ? 0 : t2->val;
            int value = t1Val + t2Val + carry;
            carry = value / 10;
            value = value % 10;
            ListNode* out = new ListNode(value);
            if (t3) {
                t3->next = out;
            }
            t3 = out;
            if (t1) {
                t1 = t1-> next;
            }
            if (t2) {
                t2 = t2-> next;
            }
        }
       
        if ((!t1 && !t2 && carry)){
            ListNode* out = new ListNode(carry);
            t3->next = out;
            t3 = out;
        }
        return head->next;
       
    }
};
