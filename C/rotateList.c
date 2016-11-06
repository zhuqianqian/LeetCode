/**
 * https://leetcode.com/problems/rotate-list/
 */

#include <stdlib.h>
#include <stdio.h>
#include "utils/leetcode.h"

struct ListNode* rotateRight(struct ListNode* head, int k) {
    int i;
    struct ListNode* slow, * fast;
    for(fast = head, i = 0; fast && i < k; i++, fast = fast->next);
    if(fast == NULL && i > 0) {
        k %= i;
        for(fast = head, i = 0; i < k; i++, fast = fast->next);
    }
    if(k > 0 && fast != NULL) {
        slow = head;
        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
    } 
    return head;
}

int main(int argc, char** argv) {
    struct ListNode* l, *list;
    if(argc > 1) {
        list = argv2List(argc-2, argv+2);
        list = rotateRight(list, atoi(argv[1]));
        while(list) {
            printf("%d ", list->val);
            l = list;
            list = list->next;
            free(l);
        }
    }
    return 0;
}