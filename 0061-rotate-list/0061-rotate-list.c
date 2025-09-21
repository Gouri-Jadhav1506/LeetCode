/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // Step 1: Find length of list
    int n = 1;
    struct ListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
        n++;
    }

    // Step 2: Make it a circular linked list
    tail->next = head;

    // Step 3: Find new head after rotation
    k = k % n;
    int stepsToNewHead = n - k;

    struct ListNode* newTail = tail;
    while (stepsToNewHead--) {
        newTail = newTail->next;
    }

    struct ListNode* newHead = newTail->next;

    // Step 4: Break the circle
    newTail->next = NULL;

    return newHead;
}
