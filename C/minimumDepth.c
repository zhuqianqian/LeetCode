/**
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/
 */
int minDepth(struct TreeNode* root) {
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    int d1, d2;
    d1 = root->left == NULL ? INT_MAX : minDepth(root->left);
    d2 = root->right == NULL ? INT_MAX : minDepth(root->right);
    return 1 + (d1 > d2 ? d2 : d1);
}