class Solution:
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        sign = (dividend < 0) is (divisor < 0)
        
        a, b = abs(dividend), abs(divisor)
        count = 0
        
        while a >= b:
            temp, i = b, 1
            while a >= temp:
                a -= temp
                count += i
                temp <<= 1
                i <<= 1
        
        if not sign: count = 0 - count
        return min(max(-2147483648, count), 2147483647)

if __name__ == '__main__':
    sol = Solution()
    print(sol.divide(-7, 3))
