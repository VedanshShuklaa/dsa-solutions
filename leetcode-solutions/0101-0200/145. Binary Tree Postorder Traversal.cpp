/*
Problem: Binary Tree Postorder Traversal
Approach: Stack (Recursion)
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

void dfs(TreeNode* node, vector<int>& result)
{
    if(node == NULL) return;

    dfs(node->left, result);
    dfs(node->right, result);
    result.push_back(node->val);
}

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;

        dfs(root, result);

        return result;
    }
};