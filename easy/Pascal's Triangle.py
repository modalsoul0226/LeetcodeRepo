class Solution:
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        res = [[1], [1, 1]]
        
        if numRows == 0:
            return []
        elif numRows == 1:
            return [[1]]
        elif numRows == 2:
            return [[1], [1,1]]
        else:
            for i in range(3, numRows + 1, 1):
                temp = [1 for _ in range(i)]
                j = 1
                for i in range(len(res[-1]) - 1):
                    temp[j] = res[-1][i] + res[-1][i + 1]
                    j += 1
                res.append(temp)

            return res

# Alternative solution:
# class Solution:
#     def generate(self, numRows):
#         """
#         :type numRows: int
#         :rtype: List[List[int]]
#         """
#         res = [[1]]
#         for i in range(1,numRows):
#             res.append(list(map(lambda x, y : x + y, res[-1]+[0], [0]+res[-1])))
#         return res[:numRows]
         

if __name__ == '__main__':
    sol = Solution()
    print(sol.generate(5))