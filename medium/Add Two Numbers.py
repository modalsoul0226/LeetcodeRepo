# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """  
        res = None
        curr = res
        c_bit = 0
        
        while l1 or l2:
            if l1 and l2:
                sum = l1.val + l2.val + c_bit
            elif l1:
                sum = l1.val + c_bit
            else:
                sum = l2.val + c_bit
            
            c_bit = sum / 10
            sum %= 10
            node = ListNode(sum)
            if curr:
                curr.next = node
                curr = node
            else:
                res = node
                curr = res
            
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        
        if c_bit:
            curr.next = ListNode(1)
        
        return res