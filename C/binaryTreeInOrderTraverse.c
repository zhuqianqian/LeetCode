/*
 * https://leetcode.com/problems/binary-tree-inorder-traversal/
 * Do not use recursion.
 */
 
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct TreeNode *stack[1024];
int si = 0;
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int notBack = 1;
    struct TreeNode* t = root;
    int *result = NULL;
    *returnSize = 0;
    while (t) {
        if (t->left &&  notBack) {
            stack[si++] = t;
            t = t->left;
        }
        else {
         //   t = stack[--si];
            result = (int*)realloc(result, sizeof(int)*(*returnSize + 1));
            result[(*returnSize)++] = t->val;
            notBack  = 0;
            if (t->right) {
                notBack  = 1;
                stack[si++] = t->right;
            }
            t = stack[--si];
        }
    }
    return result;
 }
