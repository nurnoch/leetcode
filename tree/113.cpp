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
    void pathSumCore(TreeNode* root, int leftSum, vector<vector<int>>& result, vector<int>& solution) {
        if(root == NULL)
            return;
        solution.push_back(root->val);
        if(root->val == leftSum && root->left == NULL && root->right == NULL) {
            result.push_back(solution);
            solution.pop_back();
            return;
        }
        pathSumCore(root->left, leftSum - root->val, result, solution);
        pathSumCore(root->right, leftSum - root->val, result, solution);
        
        solution.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;
        vector<int> solution;
        pathSumCore(root, sum, result, solution);
        return result;
    }
};