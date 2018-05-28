# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Better Solution:
# class Solution(object):
#     def getIntersectionNode(self, headA, headB):
#         trav_a, trav_b = headA, headB
#         while trav_a is not trav_b:
#             trav_a = headB if not trav_a else trav_a.next
#             trav_b = headA if not trav_b else trav_b.next
#         return trav_a

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        if not headA or not headB: return None
        
        currA, currB = headA, headB
        countA, countB = 0, 0
        while currA.next:
            currA = currA.next
            countA += 1
            
        while currB.next:
            currB = currB.next
            countB += 1
        
        if currB != currA: return None
        
        currA, currB = headA, headB
        while countA > countB:
            currA = currA.next
            countA -= 1
        while countB > countA:
            currB = currB.next
            countB -= 1
        
        while currA:
            if currA == currB: return currA
            
            currA, currB = currA.next, currB.next