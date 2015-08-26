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
    int sumNumbersCore(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return root->val + 10 * sum;
        int leftSum = sumNumbersCore(root->left, 10 * sum + root->val);
        int rightSum = sumNumbersCore(root->right, 10 * sum + root->val);
        return leftSum + rightSum;
    }

    int sumNumbers(TreeNode* root) {
        return sumNumbersCore(root, 0);
    }
};