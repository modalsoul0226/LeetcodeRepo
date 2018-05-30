import math

class Solution:
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        return math.factorial(m + n - 2)/(math.factorial(m - 1) * math.factorial(n - 1))
# class Solution:
#     def uniquePaths(self, m, n):
#         """
#         :type m: int
#         :type n: int
#         :rtype: int
#         """
#         if m == 0 or n == 0:
#             return 0
#         elif m == n == 1:
#             return 1
#         elif m == 1:
#             return self.uniquePaths(m, n - 1)
#         elif n == 1:
#             return self.uniquePaths(m - 1, n)
#         else:
#             return self.uniquePaths(m - 1, n) + self.uniquePaths(m, n - 1)

if __name__ == '__main__':
    sol = Solution()
    print(sol.uniquePaths(23, 12))