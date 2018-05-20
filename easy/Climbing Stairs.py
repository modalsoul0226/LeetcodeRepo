
import math

class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        count = 0
        
        i = n % 2
        for j in range(i, n + 1, 2):
            k = (n - j) // 2
            count += math.factorial(j + k) / (math.factorial(j) * math.factorial(k))
        
        return count

if __name__ == '__main__':
    sol = Solution()
    print(sol.climbStairs(4))