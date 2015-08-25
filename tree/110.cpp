/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        return 1 + max(leftDepth, rightDepth);
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        if(abs(leftDepth - rightDepth) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};