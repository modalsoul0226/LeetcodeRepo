/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode prev = null, i = head, j = head;
        while (j != null && j.next != null) {
            prev = i;
            i = i.next;
            j = j.next.next;
        }
        prev.next = null;
        
        ListNode l1 = sortList(head);
        ListNode l2 = sortList(i);
        return merge(l1, l2);
    }
    
    public ListNode merge(ListNode l1, ListNode l2) {
        ListNode first = new ListNode(0), l = first;
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                l.next = l1;
                l1 = l1.next;
            } else {
                l.next = l2;
                l2 = l2.next;
            }
            l = l.next;
        }
        if (l1 == null) l.next = l2;
        else l.next = l1;
        return first.next;
    }
}