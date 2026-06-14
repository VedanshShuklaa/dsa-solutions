/*
Problem: Maximum Twin Sum of a Linked List
Approach: Stack
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
    int returnLength(ListNode* head)
    {
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL)
        {
            len++;
            temp = temp->next;
        }

        return len;
    }

    int pairSum(ListNode* head) {
        stack<int> s;
        int maxSum = -1;

        int i = 0;
        int n = returnLength(head);

        while(head != NULL)
        {
            if(i < n / 2)
                s.push(head->val);
            else
            {
                int sum = s.top() + head->val;
                if(sum > maxSum) maxSum = sum;
                s.pop();
            }
            head = head->next;
            i++;
        }

        return maxSum;
    }
};