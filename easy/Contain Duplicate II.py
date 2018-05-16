class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        table = {}
        if k == 0 or not nums:
            return False
        
        for i in range(len(nums)):
            if nums[i] in table:
                if i - table[nums[i]] <= k:
                    return True
            table[nums[i]] = i
        
        return False    