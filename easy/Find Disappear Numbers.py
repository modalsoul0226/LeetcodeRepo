class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        table = [0] * len(nums)
        res = []
        
        for i in nums:
            table[i - 1] = 1
            
        for i in range(len(nums)):
            if not table[i]:
                res.append(i + 1)
        
        return res