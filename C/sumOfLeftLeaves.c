/**
 * https://leetcode.com/problems/sum-of-left-leaves/
 */
 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
int sumLeft(struct TreeNode* root, int dir) {
    if(root==NULL) {return 0;}
    if(root->left == NULL && root->right==NULL) {
        return dir == -1? root->val : 0;
    }
    return sumLeft(root->left, -1) + sumLeft(root->right, 1);
}

int sumOfLeftLeaves(struct TreeNode* root) {
    return sumLeft(root, 0);
}

