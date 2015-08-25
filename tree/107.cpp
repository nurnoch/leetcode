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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        int curCount = 1;
        int nextCount = 0;
        vector<int> level;
        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            level.push_back(cur->val);
            if(cur->left) {
                q.push(cur->left);
                ++nextCount;
            }
            if(cur->right) {
                q.push(cur->right);
                ++nextCount;
            }
            if(--curCount == 0) {
                result.push_back(level);
                curCount = nextCount;
                nextCount = 0;
                level.clear();
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};