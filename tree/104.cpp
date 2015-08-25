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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return 1 + max(leftDepth, rightDepth);
    }
};

// iteratively
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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        int curCount = 1;
        int nextCount = 0;
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if(cur->left) {
                q.push(cur->left);
                ++nextCount;
            }
            if(cur->right) {
                q.push(cur->right);
                ++nextCount;
            }
            if(--curCount == 0) {
                ++depth;
                curCount = nextCount;
                nextCount = 0;
            }
        }
        return depth;
    }
};