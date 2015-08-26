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
    void postorder(TreeNode* root, vector<int>& result) {
        if(root == NULL)
            return;
        postorder(root->left, result);
        postorder(root->right, result);
        result.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL)
            return result;
        postorder(root, result);
        return result;
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL)
            return result;
        stack<TreeNode*> stk;
        stack<TreeNode*> stk2;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode* cur = stk.top();
            stk.pop();
            stk2.push(cur);
            if(cur->left)
                stk.push(cur->left);
            if(cur->right)
                stk.push(cur->right);
        }
        while(!stk2.empty()) {
            TreeNode* cur = stk2.top();
            stk2.pop();
            result.push_back(cur->val);
        }
        return result;
    }
};