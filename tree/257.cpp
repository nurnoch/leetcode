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
    void getPaths(TreeNode* root, vector<string>& result, string str) {
        if(root->left == NULL && root->right == NULL) {
            result.push_back(str);
            return;
        }

        if(root->left)
            getPaths(root->left, result, str + "->" + to_string(root->left->val));
        if(root->right)
            getPaths(root->right, result, str + "->" + to_string(root->right->val));
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(root == NULL)
            return result;
        getPaths(root, result, to_string(root->val));
        return result;
    }
};