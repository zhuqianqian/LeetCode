/**
* Copyright (c) 2016, Qianqian Zhu (zhuqianqian.299@gmail.com)
*
* leetcode.c: The source file that implements the common used
* helper functions that can be used in Leetcode Online Judge
* exercises (https:leetcode.com/problems).
*
* Licensed Under GNU Public License Version 3.
*/

#include "leetcode.h"
#include <stdlib.h>
#include <string.h>

#define createListNode(n) { \
    (n) = (struct ListNode*)malloc(sizeof(struct ListNode)); \
    (n)->next = NULL; }

#define createListNodeV(n, v) {createListNode(n); (n)->val = (v);}

#define createTreeNode(t) {\
    (t) = (struct TreeNode*)malloc(sizeof(struct TreeNode));\
    (t)->left = (t)->right = NULL;}

#define createTreeNodeV(t, v) {createTreeNode(t); (t)->val = (v);}

#define createData(t, n) (t*)malloc(sizeof(t) * (n));

int* argv2Ints(int argc, char** argv) {
    int i;
    int* ints = createData(int, argc);
    for (i = 0; i < argc; ++i) {
        *(ints + i) = atoi(argv[i]);
    }
    return ints;
}

struct ListNode* argv2List(int argc, char** argv) {
    if (argc < 1) return NULL;
    struct ListNode* head, * p, * prev;
    int i;
    createListNodeV(head, atoi(argv[0]));
    prev = head;
    for (i = 1; i < argc; ++i) {
        createListNodeV(p, atoi(argv[i]));
        prev->next = p;
        prev = p;
    }
    return head;
}

struct ListNode* str2List(char* line, char *sep) {
    int argc;
    char **argv = NULL;
    char *p;
    if (line == NULL) { return NULL; }
    for (argc = 0, p = strtok(line, sep);
    p; p = strtok(NULL, sep)) {
        argc++;
        argv = realloc(argv, sizeof(char *) * argc);
        argv[argc - 1] = p;
    }
    return argv2List(argc, argv);
}

struct TreeNode* 
createTreeRecursively(int level, int offset, int argc, char** argv) {
    int pos = (1 << level) - 1 + offset * 2;
    int current = (1 << (level - 1)) - 1 + offset;
    if (current >= argc) { return NULL; }
    struct TreeNode *p;
    if (!strcmp(argv[current], "#")) { return NULL; }
    createTreeNodeV(p, atoi(argv[current]));
    p->left = createTreeRecursively(level + 1, offset * 2, argc, argv);
    p->right = createTreeRecursively(level + 1, offset * 2 + 1, argc, argv);
    return p;
}

struct TreeNode* argv2Tree(int argc, char** argv) {
    return createTreeRecursively(1, 0, argc, argv);
}

struct TreeNode* str2Tree(char* line, char* sep) {
    int argc;
    char **argv = NULL;
    char *p;
    if (line == NULL) { return NULL; }
    for (argc = 0, p = strtok(line, sep);
         p; p = strtok(NULL, sep)) {
        argc++;
        argv = realloc(argv, sizeof(char *) * argc);
        argv[argc - 1] = p;
    }
    return argv2Tree(argc, argv);
}

struct TreeLinkNode* argv2TreeLink(int argc, char **argv) {

}

struct TreeLinkNode* str2TreeLink(char* line, char *sep) {

}


void freeList(struct ListNode* head) {
    struct ListNode* p;
    while (head) {
        p = head;
        head = head->next;
        free(p);
    }
}

void freeTree(struct TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}