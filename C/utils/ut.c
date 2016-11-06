/**
* Copyright (c) 2016, Qianqian Zhu (zhuqianqian.299@gmail.com)
*
* ut.c: A unit test source to test the uutility function in
* leetcode.c
*
* Licensed Under GNU Public License Version 3.
*/

#include "leetcode.h"
#include <stdlib.h>
#include <stdio.h>

#define createData(t, n) (t*)malloc(sizeof(t) * (n));

void test_argv2Ints(int argc, char **argv) {
    printf("Running %s...", __FUNCTION__);
}

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
            notBack = 0;
            if (t->right) {
                notBack = 1;
                stack[si++] = t->right;
            }
            t = stack[--si];
        }
    }
    return result;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Test <function> [argvs]...\n");
        return 0;
    }
    int *ints, i, size;
    struct ListNode * list, * p;
    struct TreeNode * root;
    if (!strcmp(argv[1], "ints")) {
        ints = argv2Ints(argc - 2, argv + 2);
        for (i = 0; i < argc - 2; ++i) {
            printf("%d ", ints[i]);
        }
        free(ints);
    }
    else if (!strcmp(argv[1], "list")) {
        list = argv2List(argc - 2, argv + 2);
        for (p = list; p; ) {
            printf("%d ", p->val);
            list = list->next;
            free(p); p = list;
        }
    }
    else if (!strcmp(argv[1], "tree")) {
        root = str2Tree(argv[2], ",");
        ints = inorderTraversal(root, &size);
        for (i = 0; i < size; ++i) {
            printf("%d ", ints[i]);
        }
        freeTree(root);
        free(ints);
    }
    return 0;
}