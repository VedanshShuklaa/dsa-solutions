/*
Problem: Balanced Binary Tree
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

 int height(TreeNode* node)
 {
    if(node == NULL) return 0;

    return 1 + max(height(node->left), height(node->right));
 }

 bool checkBalance(TreeNode* node)
 {
    if(node == NULL) return true;

    int leftH = height(node->left);
    int rightH = height(node->right);

    return (abs(leftH - rightH) < 2) && checkBalance(node->left) && checkBalance(node->right);
 }

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return checkBalance(root);
    }
};