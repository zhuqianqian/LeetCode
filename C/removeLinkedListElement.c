/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {    
    struct ListNode temp;
    struct ListNode *p = NULL;
    temp.next = head;
    p = head; head = &temp;
    while(p) {
        if(p->val == val) {
            head->next = p->next;
            free(p);
            p = head->next;
        }
        else {
            head = p;
            p = p->next;
        }
    }
    return temp.next;
}
