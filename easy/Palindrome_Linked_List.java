/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) return true;
        ListNode slow = head, fast = head.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        slow.next = reverseLinkedListV2(slow.next);
        slow = slow.next;
        while (slow != null) {
            if (head.val != slow.val) return false;
            slow = slow.next;
            head = head.next;
        }
        return true;
    }
    
    // Iterative method.
    public ListNode reverseLinkedListV1(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode pre = null, cur = head, next = null;
        while (cur != null) {
            next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    
    // Recursice methode.
    public ListNode reverseLinkedListV2(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode newHead = reverseLinkedListV2(head.next);
        head.next.next = head;
        head.next = null;
        return newHead;
    }
}