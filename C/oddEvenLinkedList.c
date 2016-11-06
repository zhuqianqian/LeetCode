#include <stdio.h>
#include <stdlib.h>
#include "utils/leetcode.h"

/**
 * 4ms for 70 test cases on Leetcode
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode* p1, *p2, *t;
    p1 = head; p2 = NULL;
    if (p1) p2 = p1->next;
    while (head && head->next) {
        t = head->next;
        head->next = head->next->next;
        if (head->next) {
            t->next = head->next->next;
            head = head->next;
        }
    }
    if(p2!=NULL) head->next = p2;
    return p1;    
}

int main(int argc, char **argv) {
    struct ListNode* t;
    struct ListNode* l = argv2List(argc - 1, argv + 1);
    l = oddEvenList(l);
    while (l) {
        t = l;
        printf("%d ", l->val);
        l = l->next;
        free(t);
    }
    printf("\n");
}