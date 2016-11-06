/*
 * https://leetcode.com/problems/path-sum/
 *
 * 2015/12/31
 */
 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int sum) {
    if(root == NULL) {
        return false;
    }
    return (root->val == sum && root->left == NULL && root->right == NULL) 
        || hasPathSum(root->left, sum - root->val)  
        || hasPathSum(root->right, sum - root->val);
}
