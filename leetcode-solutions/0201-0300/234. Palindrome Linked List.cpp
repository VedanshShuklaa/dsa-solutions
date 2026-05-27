/*
Problem: Palindrome Linked List
Approach: Two Pointers
Time: O(n)
Bonus: Space Complexity O(1)
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

ListNode* reverseList(ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return head;

    ListNode* newHead = reverseList(head->next);

    head->next->next = head;

    head->next = NULL;

    return newHead;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        if(fast != NULL)    // Odd length
        {
            ListNode* mid = slow;
            slow = slow->next;
            slow = reverseList(slow);

            while(head != mid)
            {
                if(head->val == slow->val)
                {
                    head = head->next;
                    slow = slow->next;
                } else return false;
            }
        } else  // Even Length
        {
            ListNode* mid = slow;
            slow = reverseList(slow);

            while(head != mid)
            {
                if(head->val == slow->val)
                {
                    head = head->next;
                    slow = slow->next;
                } else return false;
            }
        }

        return true;
    }
};