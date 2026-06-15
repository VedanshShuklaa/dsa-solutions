/*
Problem: Delete the Middle Node of a Linked List
Approach: Two Pointers
Time: O(N)
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
    ListNode* findMiddle(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* middle = findMiddle(head);
        ListNode* prev = head;
        while(prev->next != middle) prev = prev->next;
        prev->next = middle->next;
        delete middle;
        return head;
    }
};