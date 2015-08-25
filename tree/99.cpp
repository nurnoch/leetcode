/* 99  Recover Binary Search Tree */

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
    void recoverTree(TreeNode* root) {
        if(root == NULL)
            return;
        stack<TreeNode *> stk;
        TreeNode* cur = root;
        TreeNode* prev = NULL;
        TreeNode* bigger = NULL;
        TreeNode* smaller = NULL;
        while(cur != NULL || !stk.empty()) {
            if(cur) {
                stk.push(cur);
                cur = cur->left;
            }
            else {
                cur = stk.top();
                stk.pop();
                if(prev != NULL && prev->val > cur->val) {
                    if(bigger == NULL)  {
                        bigger = prev;
                        smaller = cur;  // 相邻
                    }
                    else {
                        smaller = cur;
                        break;
                    }
                }
                prev = cur;
                cur = cur->right;
            }
        }
        int temp = bigger->val;
        bigger->val = smaller->val;
        smaller->val = temp;
    }
};


// O(1) space Solution
    void recoverTree(TreeNode* root) {
        TreeNode* bigger = NULL;
        TreeNode* smaller = NULL;
        TreeNode* pre = NULL;
        
        TreeNode* cur = root;
        while(cur != NULL) {
            if(cur->left) {
                // find predecessor
                TreeNode* prev = cur->left;
                while(prev->right && prev->right != cur)
                    prev = prev->right;
                    
                // threading already exists
                if(prev->right) {
                    if(pre != NULL && pre->val > cur->val) {
                        if(bigger == NULL) {
                            bigger = pre;
                            smaller = cur;
                        }
                    else
                        smaller = cur;
                    }
                    
                    pre = cur;
                    prev->right = NULL;
                    cur = cur->right;
                }
                // construct threading
                else {  
                    prev->right = cur;
                    cur = cur->left;
                }
            }
            else {
                if(pre != NULL && pre->val > cur->val) {
                    if(bigger == NULL) {
                        bigger = pre;
                        smaller = cur;
                    }
                    else
                        smaller = cur;
                }
                
                pre = cur;
                cur = cur->right;
            }
        }
        
        int temp = bigger->val;
        bigger->val = smaller->val;
        smaller->val = temp;
    }