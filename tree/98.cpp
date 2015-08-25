/* 98	Validate Binary Search Tree */

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
    bool isValid(TreeNode* root, long long upper, long long lower) {
        if(root == NULL)
            return true;
        return (root->val < upper && root->val > lower) && isValid(root->left, root->val, lower) && isValid(root->right, upper, root->val);
    }
    
    
    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MAX, LLONG_MIN);
    }
};

// iteratively
bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
            
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        TreeNode* prev = NULL;
        while(cur != NULL || !stk.empty()) {
            if(cur) {
                stk.push(cur);
                cur = cur->left;
            }
            else {
                cur = stk.top();
                stk.pop();
                if(prev != NULL && prev->val >= cur->val)
                    return false;
                prev = cur;
                cur = cur->right;
            }
        }
        return true;
    }