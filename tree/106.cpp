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
    TreeNode* build(vector<int>& inorder, int s1, int e1, vector<int>& postorder, int s2, int e2, unordered_map<int, int>& table) {
        if(s2 > e2)
            return NULL;
        TreeNode* root = new TreeNode(postorder[e2]);
        int index = table[postorder[e2]];
        root->left = build(inorder, s1, index-1, postorder, s2, s2+index-s1-1, table);
        root->right = build(inorder, index+1, e1, postorder, s2+index-s1, e2-1, table);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int m = postorder.size();
        if(n == 0 || m != n)
            return NULL;
        unordered_map<int, int> table;
        for(int i = 0; i < n; ++i)
            table[inorder[i]] = i;
        return build(inorder, 0, n-1, postorder, 0, n-1, table);
    }
};