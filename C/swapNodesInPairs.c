/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* w, *p, *n;
    struct ListNode dummyHead;
    dummyHead.next = head;
    w = &dummyHead;
    if(head == NULL) {
        return head;
    }
    p = head;
    for(n = head->next; p && n;) {
        p->next = n->next;
        n->next = p;
        w->next = n;
        w = p;
        p = p->next;
        if(p) {
            n = p->next;
        }
    }
    return dummyHead.next;
}