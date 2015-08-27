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
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        int leftNum = countNodes(root->left);
        int rightNum = countNodes(root->right);
        return 1 + leftNum + rightNum;
    }

    int kthSmallest(TreeNode* root, int k) {
        int leftNum = countNodes(root->left);
        int rightNum = countNodes(root->right);
        if(k == leftNum + 1)
            return root->val;
        else if(k <= leftNum)
            return kthSmallest(root->left, k);
        else
            return kthSmallest(root->right, k - leftNum - 1);
    }
};

