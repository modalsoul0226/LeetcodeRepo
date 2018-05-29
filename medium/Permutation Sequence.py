import math

class Solution:
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        res = ''
        d_list = [i for i in range(1, n + 1)]
        
        while n > 0:
            perm = math.factorial(n)
            div = perm // n
            rem = k % div
            idx = k // div + 1 if rem else k // div
            
            digit = d_list[idx - 1]
            res += str(digit)
            
            n, k = n - 1, rem
            d_list.remove(digit)
        
        return res

if __name__ == '__main__':
    sol = Solution()
    print(sol.getPermutation(4, 9))