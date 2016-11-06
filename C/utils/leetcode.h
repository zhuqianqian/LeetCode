/**
 * Copyright (c) 2016, Qianqian Zhu (zhuqianqian.299@gmail.com)
 *
 * leetcode.h: The header file that declares the common used
 * structure and helper functions that can be used in Leetcode
 * Online Judge exercises (https:leetcode.com/problems)
 *
 * Licensed Under GNU Public License Version 3.
 */

#ifndef _LEETCODE_H_
#define _LEETCODE_H__

typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
}TreeNode;

typedef struct TreeLinkNode {
    int val;
    struct TreeLinNode *left, *right, *next;
}TreeLinkNode;

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

int* argv2Ints(int argc, char** argv);

struct ListNode* argv2List(int argc, char** argv);

struct ListNode* str2List(char* line, char *sep);

struct TreeNode* argv2Tree(int argc, char** argv);

struct TreeNode* str2Tree(char* line, char *sep);

struct TreeLinkNode* str2TreeLink(char* s, char *sep);

void freeList(struct ListNode* head);

void freeTree(struct TreeNode* root);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _LEETCODE_H_ */
