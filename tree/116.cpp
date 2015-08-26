/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        TreeLinkNode* cur = root;  
        TreeLinkNode* prev = NULL;  // 当前遍历的前一个节点
        TreeLinkNode* head = NULL;  // 当前层的第一个节点
        while(cur) {
            while(cur) {  // 连接当前节点的孩子们
                if(cur->left) {
                    if(prev == NULL)
                        head = cur->left;
                    else
                        prev->next = cur->left;
                    prev = cur->left;
                }
                if(cur->right) {
                    if(prev == NULL)
                        head = cur->right;
                    else
                        prev->next = cur->right;
                    prev = cur->right;
                }
                cur = cur->next;
            } 
            cur = head;  // 进入下一层
            head = NULL;
            prev = NULL;
        }
    }
};

// another Solution
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        TreeLinkNode* prev = root;
        while(prev->left) {
            TreeLinkNode* cur = prev;
            while(cur) {
                if(cur->left)
                    cur->left->next = cur->right;
                if(cur->next)
                    cur->right->next = cur->next->left;
                cur = cur->next;
            }
            prev = prev->left;
        }
    }
};