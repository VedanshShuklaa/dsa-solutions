/*
Problem: Add Two Numbers
Approach: Just Add
Time: O(n)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* l3 = new ListNode;
        l3->val = l1->val + l2->val;
        l3->next = NULL;
        carry = l3->val / 10;
        l3->val = l3->val % 10;
        l1 = l1->next;
        l2 = l2->next;
        ListNode* temp = l3;

        while(l1 != NULL || l2 != NULL || carry != 0)
        {
            ListNode* node = new ListNode;
            int l1Val = l1 != NULL ? l1->val : 0;
            int l2Val = l2 != NULL ? l2->val : 0;

            node->val = l1Val + l2Val + carry;
            carry = node->val / 10;
            node->val = node->val % 10;
            node->next = NULL;

            temp->next = node;
            temp = temp->next;

            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
        }

        return l3;
        
    }
};