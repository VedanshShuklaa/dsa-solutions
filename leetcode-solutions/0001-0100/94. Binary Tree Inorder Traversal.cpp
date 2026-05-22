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

void traverse(TreeNode* node, vector<int>& out)
{
    if(node == NULL) 
    {
        return;
    }

    traverse(node->left, out);
    out.push_back(node->val);
    traverse(node->right, out);
}

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> out = {};
        traverse(root, out);
        return out;
    }
};