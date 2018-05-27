class Solution:
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        res = 1
        
        if n < 0:
            n = abs(n)
            x = 1 / x
        
        for _ in range(n):
            res *= x
        
        return round(res, 5)

if __name__ == '__main__':
    sol = Solution()
    print(sol.myPow(2.00000, -2))