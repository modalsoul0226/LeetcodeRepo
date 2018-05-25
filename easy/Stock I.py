# The normal method: find the min val before each element
# import sys

# class Solution:
#     def maxProfit(self, prices):
#         """
#         :type prices: List[int]
#         :rtype: int
#         """
#         if not prices:
#             return 0
        
#         max_prof = 0
#         min_p = sys.maxsize
        
#         for i in range(len(prices)):
#             if prices[i] < min_p:
#                 min_p = prices[i]
#             elif prices[i] - min_p > max_prof:
#                 max_prof = prices[i] - min_p
            
#         return max_prof

# The general method: find the largest contiguous block
class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        res, curr_max = 0, 0
        
        for i in range(len(prices) - 1):
            curr_max = max(0, curr_max + prices[i + 1] - prices[i])
            res = max(curr_max, res)
        
        return res

if __name__ == '__main__':
    sol = Solution()
    print(sol.maxProfit([7,1,5,3,6,4]))