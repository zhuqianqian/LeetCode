/*
* https://leetcode.com/problems/copy-list-with-random-pointer/
* A linked list is given such that each node contains an additional 
* random pointer which could point to any node in the list or null.
*
* Return a deep copy of the list.
* 
* 2015/12/22
*/

#include <stdio.h>
#include <stdlib.h>

int value = 0;
struct RandomListNode {
    int label;
    struct RandomListNode *next;
    struct RandomListNode *random;
};


#define FREE_ALL(l, t)  while(l) {\
                            t = l;\
                            l = l->next;\
                            free(t); }
#define NEW_NODE(t)  {t = (struct RandomListNode *)malloc(sizeof(struct RandomListNode));\
                      t->label = value++; t->next = t->random = NULL;}

#define APPEND(p, n) {NEW_NODE(n);\
                        p->next = n; p->random = t; }


struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    struct RandomListNode *origin, *copy, *temp;
    temp = head;
    copy = NULL;
    /* Make a copy of each node and insert the copy immediately after it */
    for (origin = head ? head->next : NULL; temp; ) {
        copy = (struct RandomListNode *)malloc(sizeof(struct RandomListNode));
        copy->label = temp->label;  temp->next = copy;  copy->next = origin;
        temp = origin;
        if (origin) {
            origin = origin->next;
        }
    }
    /* Assign the random node for the copied nodes */
    for (origin = head; origin; origin = origin->next->next) {
        origin->next->random = origin->random ? origin->random->next: NULL;
    }
    /* Split the whole list into two */
    if (head) {
        copy = head->next;
        for (origin = head, temp = copy; origin; origin = origin->next, temp = origin->next) {
            origin->next = temp->next;
            if (!temp->next) {
                break;
            }
            temp->next = temp->next->next;
        }
    }
    return copy;
}

int main(int argc, char ** argv) {
    struct RandomListNode *a = NULL, *t, *n, *b;
    printf("copy of RandomListNode should be null: %d\n", copyRandomList(a) == NULL);
    NEW_NODE(a);
    APPEND(a, t);
    APPEND(t, n);
    APPEND(n, t);
   // t->random = t;
    b = copyRandomList(a);
    for (n = a, t = b; t; n = n->next, t = t->next) {
        printf("a: label:%d, random:%d\n", n->label, n->random? t->random->label : -1);
        printf("b: label:%d, random:%d\n", t->label, t->random? t->random->label : -1);
    }
    FREE_ALL(a, n);
    FREE_ALL(t, n);
    return 0;
}
