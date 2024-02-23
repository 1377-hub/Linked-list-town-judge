#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to find the intersection point of two linked lists
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    // Base cases
    if (headA == NULL || headB == NULL) {
        return NULL;
    }

    // Pointers for traversing the linked lists
    struct ListNode *ptrA = headA;
    struct ListNode *ptrB = headB;

    // Traverse both lists until they either meet or reach the end
    while (ptrA != ptrB) {
        // If either list reaches the end, reset its pointer to the head of the other list
        ptrA = (ptrA == NULL) ? headB : ptrA->next;
        ptrB = (ptrB == NULL) ? headA : ptrB->next;
    }

    // Return the intersection point (or NULL if there's no intersection)
    return ptrA;
}

// Example usage
int main() {
    // Creating linked lists
    struct ListNode *a1 = malloc(sizeof(struct ListNode));
    struct ListNode *a2 = malloc(sizeof(struct ListNode));
    struct ListNode *b1 = malloc(sizeof(struct ListNode));
    struct ListNode *b2 = malloc(sizeof(struct ListNode));
    struct ListNode *b3 = malloc(sizeof(struct ListNode));
    struct ListNode *c1 = malloc(sizeof(struct ListNode));
    struct ListNode *c2 = malloc(sizeof(struct ListNode));
    struct ListNode *c3 = malloc(sizeof(struct ListNode));

    a1->val = 1; a1->next = a2;
    a2->val = 2; a2->next = c1;

    b1->val = 3; b1->next = b2;
    b2->val = 4; b2->next = b3;
    b3->val = 5; b3->next = c1;

    c1->val = 6; c1->next = c2;
    c2->val = 7; c2->next = c3;
    c3->val = 8; c3->next = NULL;

    // Finding the intersection point
    struct ListNode *result = getIntersectionNode(a1, b1);

    // Displaying the result
    if (result != NULL) {
        printf("Intersection point value: %d\n", result->val);
    } else {
        printf("No intersection point\n");
    }

    // Freeing memory
    free(a1); free(a2);
    free(b1); free(b2); free(b3);
    free(c1); free(c2); free(c3);

    return 0;
}
