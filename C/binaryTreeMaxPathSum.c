/**
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX(a,b) (a) > (b) ? (a) : (b);

int max;

int getLength(struct TreeNode* root) {
    if(root == NULL) return 0;
    int left = getLength(root->left);
    int right = getLength(root->right);
    int leftMax = MAX(0, left);
    int rightMax = MAX(0,right);
    max = MAX(max, (leftMax+rightMax+root->val));
    return MAX(leftMax+root->val, rightMax+root->val);
}

int maxPathSum(struct TreeNode* root) {
   if(root == NULL) {
        return INT_MIN;
    }
    max=INT_MIN;
    int l;
    l = getLength(root);
    return MAX(l, max);
}