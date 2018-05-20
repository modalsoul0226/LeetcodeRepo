class Solution:
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x == 0:
            return 0
        
        power = 1
        while (power ** 2) <= x:
            if power ** 2 == x:
                return power
            power *= 2
        
        start, end = power / 2, power
        while end >= start:
            if end == start + 1:
                return start
            
            mid = (start + end) // 2
            
            if mid ** 2 <= x:
                start = mid
            else:
                end = mid

if __name__ == '__main__':
    sol = Solution()
    print(sol.mySqrt(100))