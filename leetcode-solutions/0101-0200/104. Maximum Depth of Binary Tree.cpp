/*
Problem: Maximum Depth of Binary Tree
Approach: Recursion
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

int depth(TreeNode* node)
{
    if(node == NULL) return 0;

    return 1 + max(depth(node->left), depth(node->right));
}

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int maxD = depth(root);
        return maxD;
    }
};