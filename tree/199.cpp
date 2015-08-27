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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root == NULL)
            return result;
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
                result.push_back(cur->val);
                curCount = nextCount;
                nextCount = 0;
            }
        }
        return result;
    }
};