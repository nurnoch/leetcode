/*      101 Symmetric Tree */

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
    bool isSymmetricTree(TreeNode* leftChild, TreeNode* rightChild) {
        if(leftChild == NULL || rightChild == NULL)
            return leftChild == rightChild;
        return (leftChild->val == rightChild->val) && isSymmetricTree(leftChild->left, rightChild->right) && isSymmetricTree(leftChild->right, rightChild->left);
        
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return isSymmetricTree(root->left, root->right);
    }
};