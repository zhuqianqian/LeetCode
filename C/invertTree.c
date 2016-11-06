/*
* https://leetcode.com/problems/invert-binary-tree/
*
* 2015/12/21
*/

struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/* recursive solutin */
struct TreeNode * invertTree(struct TreeNode *root) {
    if (root == NULL) { return NULL; }
    struct TreeNode *tmp = root->left;
    // root->left = root->right;
    // root->right = tmp;

    root->left = invertTree(root->right);
    root->right = invertTree(tmp);
    return root;
}
