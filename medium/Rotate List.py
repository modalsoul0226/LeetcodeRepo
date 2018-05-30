# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if not head: return None
        count, curr = 0, head
        while curr:
            count += 1
            curr = curr.next
        
        count = k % count
        if not count: return head
        
        start, end = head, head
        while count:
            end = end.next
            count -= 1
        while end.next:
            start, end = start.next, end.next
        
        end.next = head
        head = start.next
        start.next = None
        return head
        