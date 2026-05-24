/*
Problem: Same Tree
Approach: DFS
Time: O(n) where n is number of nodes
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 bool checkSame(TreeNode* nodeA, TreeNode* nodeB)
 {
    if(nodeA == NULL && nodeB != NULL) return false;
    if(nodeA == NULL && nodeB == NULL) return true;
    if(nodeA != NULL && nodeB == NULL) return false;

    return 
        (nodeA->val == nodeB->val)
        && checkSame(nodeA->left, nodeB->left) 
        && checkSame(nodeA->right, nodeB->right);
 }
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return checkSame(p, q);
    }
};