/*
Problem: Symmetric Tree
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

bool checkSymmetry(TreeNode* nodeA, TreeNode* nodeB)
{
    if(nodeA == NULL && nodeB != NULL) return false;
    if(nodeA == NULL && nodeB == NULL) return true;
    if(nodeA != NULL && nodeB == NULL) return false;

    return 
        (nodeA->val == nodeB->val)
        && checkSymmetry(nodeA->left, nodeB->right) 
        && checkSymmetry(nodeA->right, nodeB->left);
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return checkSymmetry(root, root);
    }
};