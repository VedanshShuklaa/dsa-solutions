/*
Problem: Reorder List
Approach: Deque
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
    void reorderList(ListNode* head) {
        deque<int> dq;

        ListNode* curr = head;
        while(curr != NULL)
        {
            dq.push_back(curr->val);
            curr = curr->next;
        }

        int i = 0;

        curr = head;

        while(!dq.empty())
        {
            if(i%2 == 0)
            {
                curr->val = dq.front();
                dq.pop_front();
                curr = curr->next;
                i++;
            } else
            {
                curr->val = dq.back();
                dq.pop_back();
                curr = curr->next;
                i++;
            }
        }
    }
};