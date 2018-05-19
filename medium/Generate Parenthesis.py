class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        dp = [[] for i in range(n + 1)]
        dp[0].append('')
        for i in range(n + 1):
            for j in range(i):
                dp[i] += ['(' + x + ')' + y for x in dp[j] for y in dp[i - j - 1]]
        return dp[n]

# class Solution:
#     def generateParenthesis(self, n):
#         """
#         :type n: int
#         :rtype: List[str]
#         """
#         if n == 0:
#             return []
#         elif n == 1:
#             return ['()']
#         else:
#             res = []
#             base = self.generateParenthesis(n - 1)
            
#             for each in base:
#                 res.append('(' + each + ')')
#             for i in range(len(base) - 1):
#                 res.append(base[i] + '()')
#             for j in range(len(base) - 1):
#                 res.append('()' + base[j])
            
#             res.append(base[len(base) - 1] + '()')
#             return res

if __name__ == '__main__':
    sol = Solution()
    for each in sol.generateParenthesis(5):    
        print(each)