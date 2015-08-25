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
    TreeNode* build(vector<int>& preorder, int s1, int e1, vector<int>& inorder, int s2, int e2, unordered_map<int, int>& table) {
        if(s1 > e1)
            return NULL;
        TreeNode* root = new TreeNode(preorder[s1]);
        int index = table[preorder[s1]];
        root->left = build(preorder, s1+1, s1+index-s2, inorder, s2, index-1, table);
        root->right = build(preorder, s1+index-s2+1, e1, inorder, index+1, e2, table);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int m = inorder.size();
        if(n == 0 || n != m)
            return NULL;
        unordered_map<int, int> table;
        for(int i = 0; i < n; ++i)
            table[inorder[i]] = i;
        return build(preorder, 0, n-1, inorder, 0, n-1, table);
    }
};