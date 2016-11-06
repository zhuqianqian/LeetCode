/*
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 * Given a binary tree, return the zigzag level order traversal 
 * of its nodes' values. (ie, from left to right, then right to left 
 * for the next level and alternate between).
 *
 * 2015/12/30
 */

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 
 /**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** zigzagLevelOrder(struct TreeNode* root, int** columnSizes, int* returnSize) {
    struct TreeNode *stack1[1024] = { NULL },
        *stack2[1024] = { NULL };
    struct TreeNode **s1, **s2, **t;
    int direction = 0;
    int *ps = NULL;
    int ** result = NULL;
    *returnSize = 0;
    *columnSizes = NULL;
    stack1[1] = root; stack2[1] = stack1[2] = NULL;
    s1 = stack1+1; s2 = stack2+1;
    while (*s1 != NULL) {
        *columnSizes = (int *)realloc(*columnSizes, sizeof(int) * ++(*returnSize));
        ps = columnSizes[0] + *returnSize - 1;
        result = (int **)realloc(result, sizeof(int*)* *returnSize);
        result[*returnSize - 1] = NULL;
        for (*ps = 0; *s1 != NULL; s1--) {
            result[*returnSize - 1] = (int *)realloc(result[*returnSize - 1], sizeof(int) * ++(*ps));
            result[*returnSize - 1][*ps - 1] = (*s1)->val;
            if (direction ) {  // current direction: left->right
                if ((*s1)->right != NULL) { *s2++ = (*s1)->right; }
                if ((*s1)->left != NULL) { *s2++ = (*s1)->left; }
            }
            else { // current direction: right->left                

                if ((*s1)->left != NULL) { *s2++ = (*s1)->left; }
                if ((*s1)->right != NULL) { *s2++ = (*s1)->right; }
            }
        }
        s2 -= 1; s1 += 1;
        t = s1;  s1 = s2; s2 = t;
        direction = !direction;
    }
    return result;
}
