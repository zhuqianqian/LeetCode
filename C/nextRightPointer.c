/*
* https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
*
* 2015/12/26
*/

#include <stdio.h>
#include <stdlib.h>

int value = 1;

#define NEW_NODE(t)  {t = (struct TreeLinkNode *)malloc(sizeof(struct TreeLinkNode));\
                      t->val = value++; t->next = t->left = t->right = NULL;}

#define APPEND_LEAVES(p, l, r) {NEW_NODE(l); NEW_NODE(r)\
                        p->left = l; p->right = r; }

 struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left, *right, *next;
};

/**
* Definition for binary tree with next pointer.
* struct TreeLinkNode {
*  int val;
*  struct TreeLinkNode *left, *right, *next;
* };
*/
void connect(struct TreeLinkNode *root) {
    if (root == NULL) {
        return;
    }
    struct TreeLinkNode *p = root->left, 
        *up = root, *q;
    while (p) {
        p->next = up->right;
        for (q = up; q->next; q = q->next) {
            p = p->next;
            p->next = q->next->left;
            p = p->next;
            p->next = q->next->right;           
        }
        up = up->left;
        p = up->left;
    }
}

void free_tree(struct TreeLinkNode *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(int argc, char **argv) {

    struct TreeLinkNode *root, *l, *r;
    NEW_NODE(root);
    APPEND_LEAVES(root, l, r);
    APPEND_LEAVES(root->left, l, r);
    APPEND_LEAVES(root->right, l, r);
    connect(root);
    for (l = root; l; l = l->left) {
        for (r = l; r; r = r->next) {
            printf("%d->", r->val);
        }
        printf("NULL\n");
    }
    free_tree(root);
    return 0;
}
