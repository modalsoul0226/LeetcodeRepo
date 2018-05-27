# General solution for both Single Number I and Single Number II. 
# class Solution:
#     def singleNumber(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: int
#         """
#         return 2 * sum(set(nums)) - sum(nums)

# Solution only works for Single Number I
class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = 0

        for num in nums:
            res ^= num
        return res