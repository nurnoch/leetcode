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
            return INT_MAX;
        
        if(root->left == NULL && root->right == NULL)
            return 1;
        
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        return 1 + min(leftDepth, rightDepth);
    }

    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        return getDepth(root);
    }
};