/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // Create a dummy node to handle edge cases easily (like removing head)
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        // Initialize two pointers starting from dummy
        ListNode first = dummy;
        ListNode second = dummy;

        // Move 'first' n+1 steps ahead to maintain a gap of n nodes
        for (int i = 0; i <= n; i++) {
            first = first.next;
        }

        // Move both pointers until 'first' reaches the end
        while (first != null) {
            first = first.next;
            second = second.next;
        }

        // 'second' is now at the node before the one to delete
        second.next = second.next.next;

        // Return the head (dummy.next handles the case when head is removed)
        return dummy.next;
    }
}
