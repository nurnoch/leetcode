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
        TreeNode* curLeft = root;
        int leftCount = 0;
        while(curLeft) {
            ++leftCount;
            curLeft = curLeft->left;
        }
        TreeNode* curRight = root;
        int rightCount = 0;
        while(curRight) {
            ++rightCount;
            curRight = curRight->right;
        }
        if(leftCount == rightCount)
            return pow(2, leftCount) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};