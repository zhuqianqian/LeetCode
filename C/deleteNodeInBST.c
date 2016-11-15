/*
 * https://leetcode.com/problems/delete-node-in-a-bst/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 
struct TreeNode* p; 
struct TreeNode* search(struct TreeNode* root, int key) {
    if(root == NULL) return NULL;
    if(root->val == key) { return root;}
    p = root;
    return key < root->val ? search(root->left, key) : search(root->right, key);
}
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    p = NULL;
    struct TreeNode* del_node = search(root, key);
    struct TreeNode* w, * pw;
    if(del_node != NULL) {
        
        /* Case 1: leaf node, remove directly */
        if (del_node->left == NULL && del_node->right == NULL) {
            if(p == NULL) { root = NULL;}
            else if (p->left == del_node) { p->left = NULL; }
            else { p->right = NULL; }
            free(del_node);
        }
        /* Case 2: only one branch, move the branch to replace it */
        else if (del_node->left == NULL || del_node->right == NULL) {
            w = del_node->left == NULL ? del_node->right : del_node->left;
            del_node->val = w->val;
            del_node->left = w->left;
            del_node->right = w->right;
            free(w);
        }
        /* Case 3: two branches: replace with the leftmost node of the right branch.
         * (another option: rightmost node of the left branch) 
         */
        else {
            pw = del_node; w = del_node->right;
            while(w->left!=NULL) { pw = w; w = w->left;}
            del_node->val = w->val;
            if(pw != del_node) { pw->left = w->right;}
            else {pw->right = w->right;}
            free(w);
        }
    }
    return root;  
}