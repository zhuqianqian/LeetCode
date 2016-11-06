#include <stdio.h>
#include <stdlib.h>
#include "utils/leetcode.h"

typedef struct ListNode* (*fptr)(struct ListNode *);

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* t, *next;
    if (head != NULL) {
        next = head->next;
        head->next = NULL;
        while (next) {
            t = next->next;
            next->next = head;
            head = next; next = t;
        }
    }
    return head;
}

struct ListNode* reverseListR(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    struct ListNode* t = head->next, *r;
    head->next = NULL;
    r = reverseListR(t);
    t->next = head;
    return r;    
}

int main(int argc, char** argv) {
    struct ListNode* l, * t;
    fptr f = reverseList;
    
    if (argc >= 2 && !strcmp("-r", argv[1])) {
        f = reverseListR;
        l = argv2List(argc - 2, argv + 2);
    }
    else {
        l = argv2List(argc - 1, argv + 1);
    }
    l = f(l);
    while (l) {
        printf("%d ", l->val);
        t = l; l = l->next;
        free(t);
    }
    return 0;
}