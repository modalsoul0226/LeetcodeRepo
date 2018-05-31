class Solution:
    def set_row(self, matrix, row):
        for i in range(len(matrix[row])):
            matrix[row][i] = 0
    
    def set_col(self, matrix, col):
        for i in range(len(matrix)):
            matrix[i][col] = 0
    
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        row, col = [0 for _ in range(len(matrix))], [0 for _ in range(len(matrix[0]))]
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                if not matrix[i][j]: row[i], col[j] = 1, 1
        
        for i in range(len(row)):
            if row[i]: self.set_row(matrix, i)
        for j in range(len(col)):
            if col[j]: self.set_col(matrix, j)
        
        return matrix
if __name__ == '__main__':
    sol = Solution()
    print(sol.setZeroes([
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]))