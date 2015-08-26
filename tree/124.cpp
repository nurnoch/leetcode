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
    int onePathSum(TreeNode* root, int& maxSum) {
        if(root == NULL)
            return 0;
        int leftSum = max(0, onePathSum(root->left, maxSum));
        int rightSum = max(0, onePathSum(root->right, maxSum));
        int curSum = root->val + leftSum + rightSum;
        maxSum = max(curSum, maxSum);
        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        if(root == NULL)
            return 0;
        int maxSum = INT_MIN;
        onePathSum(root, maxSum);
        return maxSum;
    }
};