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
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) {
            return 0;
        }

        // If current value is smaller than low,
        // only the right subtree can contain valid values.
        if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        }

        // If current value is greater than high,
        // only the left subtree can contain valid values.
        if (root->val > high) {
            return rangeSumBST(root->left, low, high);
        }

        // Current value is in [low, high]
        return root->val
             + rangeSumBST(root->left, low, high)
             + rangeSumBST(root->right, low, high);
    }
};