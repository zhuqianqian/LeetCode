/**
 * E: https://leetcode.com/problems/merge-two-sorted-lists/
 * M: https://leetcode.com/problems/sort-list/
 * M: https://leetcode.com/problems/insertion-sort-list/
 */
#include <stdio.h>
#include <stdlib.h>
#include "utils/leetcode.h"

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* last, head;
    last = &head;
    head.next = l1;
    while(l1 && l2) {
        if (l1->val > l2->val) {
            last->next = l2; last = l2;
            l2 = l2->next; last->next = l1;
        }
        else {
            last = l1; l1 = l1->next;
        }
    }
    if (l2 != NULL) last->next = l2;
    return head.next;
}

/**
 * Merge sort use O(nlgn) time, split method 1:
 * Starting from head, pick every the other node to 
 * get the first link, and Starting from head->next, 
 * pick every the other node to get the second.
 * 40ms for 15 cases on LeetCode.
 */
struct ListNode* sortList(struct ListNode* head) {
    struct ListNode* l1, *l2, *h;
    if (head == NULL || head->next == NULL) return head;
    l1 = head; l2 = head->next;
    while (head && head->next) {
        h = head->next;
        head->next = head->next->next;
        if (head->next) {
            h->next = head->next->next;
        }
        head = head->next;  h = h->next;
    }
    return mergeTwoLists(sortList(l1), sortList(l2));
}

/**
 * Also merge sort, but split the list with another
 * approach: both points at the head, one goes one
 * next while the other goes two next each time. This
 * splits the lists in the middle. This should be
 * faster than the first method.
 * 20ms for 15 cases on LeetCode.
 */
struct ListNode* sortList2(struct ListNode* head) {
    struct ListNode* l1, *l2, *h;
    if (head == NULL || head->next == NULL) return head;
    l1 = head;  l2 = head->next;
    while (l2 && l2->next) {
        head = head->next;
        l2 = l2->next->next;
    }
    l2 = head->next;
    head->next = NULL;
    return mergeTwoLists(sortList(l1), sortList(l2));
}

/*
 * A faster solution than the second version below because
 * it compare the last node of the sorted list with the
 * current node first instead of looping from the start
 * to find out that it should be inserted at the tail.
 * 12ms for 21 cases on LeetCode.
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode tempHead;
    struct ListNode* prev, *t, *nextProc;
    if (head == NULL) { return head; }
    tempHead.next = head;
    nextProc = head;    
    while (nextProc->next) {
        if (nextProc->val > nextProc->next->val) {
            for (prev = &tempHead, head = prev->next;
                head != nextProc->next && head->val < nextProc->next->val;
                prev = head, head = head->next);
            prev->next = nextProc->next;
            t = nextProc->next->next;
            nextProc->next->next = head;
            nextProc->next = t;
        }
        else {
            nextProc = nextProc->next;
        }
    }
    return tempHead.next;
}
/**
 * A very direct way, 64ms for 21 cases on LeetCode. 
 * Above is the optimized solution.
 */
struct ListNode* insertionSortList2(struct ListNode* head) {
    struct ListNode* prev, *t, *prevNext, *next;
    struct ListNode tempHead;
    tempHead.next = head; 
    prev = &tempHead;
    for (prevNext = head; prevNext && prevNext->next; ) {
        next = prevNext->next;
        for (prev = &tempHead, head = prev->next;
             head != next && head->val < next->val; 
             prev = head, head = head->next) ;
        if (head != next) {
            prev->next = next;
            t = next->next;
            next->next = head;
            prevNext->next = t;
        }
        else {
            prevNext = prevNext->next;
        }
    }    
    return tempHead.next;
}

int main(int argc, char **argv) {
    struct ListNode *l1, *l2;
    char **argv1, **argv2;
    int i, c1 = 0, c2 = 0;
    for (i = 1; i < argc; ++i) {
        if (!strcmp(argv[i], "-l1")) {
            argv1 = argv + i + 1;
            c1 = i + 1;
        }
        else if (!strcmp(argv[i], "-l2")) {
            argv2 = argv + i + 1;
            c2 = i + 1;
        }
    }
    l1 = argv2List( c2 > c1 ? c2 - c1 - 1 : i - c1, argv1);
    l2 = argv2List( c2 > c1 ? i - c2 : c1 - c2 - 1, argv2);
    l1 = insertionSortList(l1);
    l2 = sortList2(l2);
    l1 = mergeTwoLists(l1, l2);
    for (l2 = l1; l2; l1 = l2) {
        printf("%d ", l2->val);
        l2 = l2->next;
        free(l1);
    }
    return 0;
}