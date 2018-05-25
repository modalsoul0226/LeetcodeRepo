class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        res, start = 0, 0
        
        for i in range(len(prices)):
            if i == len(prices) - 1 or prices[i + 1] < prices[i]:
                res += prices[i] - prices[start]
                start = i + 1
        
        return res

if __name__ == '__main__':
    sol = Solution()
    print(sol.maxProfit([7,6,4,3,1]))