/* 95   Unique Binary Search Trees II */

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
    /* 每次选取一个结点作为根，然后递归求解左右子树的所有结果；
    根据左右子树返回的所有子树，依次接上根
    */
    vector<TreeNode*> generate(int start, int end) {
        if(start > end)
            return vector<TreeNode*>(1, NULL);
            
        vector<TreeNode *> result;
        for(int i = start; i <= end; ++i) {
            vector<TreeNode*> leftTree = generate(start, i - 1);
            vector<TreeNode*> rightTree = generate(i + 1, end);
            
            for(int j = 0; j < leftTree.size(); ++j)
                for(int k = 0; k < rightTree.size(); ++k) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTree[j];
                    root->right = rightTree[k];
                    result.push_back(root);
                }
        }
        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};