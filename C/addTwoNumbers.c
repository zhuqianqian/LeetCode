/*
* https://leetcode.com/problems/add_two_numbers/
*
* 2016/01/07
*/
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    struct ListNode *result, *p, *w, *l;
    if (l1 == NULL && l2 == NULL) { return NULL; }
    result = (struct ListNode *)malloc(sizeof(struct ListNode));
    p = result;
    while (l1 != NULL && l2 != NULL) {
        p->val = l1->val + l2->val + carry;
        /* If I calc the carry directly without if...else..., runtime is longer on Leetcode */
            if (p->val > 9) {
                carry = p->val / 10;
                p->val %= 10;
            }
            else { carry = 0; }
            p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            p->next->next = NULL;
            l = p; p = p->next; l1 = l1->next; l2 = l2->next;
    }
    w = l1 ? l1 : l2;
    while (w != NULL) {
        p->val = (w->val + carry);
        if (p->val > 9) {
            carry = p->val / 10;
            p->val %= 10;
        }
        else { carry = 0; }
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->next->next = NULL;
        l = p; w = w->next; p = p->next;
    }
    if (carry > 0) {
        p->val = carry;
    }
    else {
        l->next = NULL; free(p);
    }
    return result;
}

/* A more cleaner look solution, but performance is not as good as above */
struct ListNode* addTwoNumbers2(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    struct ListNode *result, *p, *w, *l;
    if (l1 == NULL && l2 == NULL) { return NULL; }
    result = (struct ListNode *)malloc(sizeof(struct ListNode));
    p = result;
    while (l1 != NULL || l2 != NULL) {
        p->val = carry;
        if (l1) {
            p->val += l1->val; l1 = l1->next;
        }
        if (l2) {
            p->val += l2->val; l2 = l2->next;
        }
        if (p->val > 9) {
            carry = p->val / 10;
            p->val %= 10;
        }
        else { carry = 0; }
        p->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->next->next = NULL;
        l = p; p = p->next;
    }
    if (carry > 0) {
        p->val = carry;
    }
    else {
        l->next = NULL; free(p);
    }
    return result;
}