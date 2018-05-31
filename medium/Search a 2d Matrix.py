class Solution:
    def search_for_row(self, matrix, start, end, target):
        if start > end:
            return -1
        
        
        mid = (start + end) // 2
        
        if matrix[mid][0] <= target <= matrix[mid][-1]: 
            return mid
        elif target < matrix[mid][0]:
            return self.search_for_row(matrix, start, mid - 1, target)
        else:
            return self.search_for_row(matrix, mid + 1, end, target)
    
    def search_for_target(self, row, start, end, target):
        if start == end:
            return row[start] == target
        
        mid = (start + end) // 2
        if row[mid] == target: return True
        elif target < row[mid]: return self.search_for_target(row, start, mid, target)
        else: return self.search_for_target(row, mid + 1, end, target)
        
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not matrix or target is None:
            return False
        
        row = self.search_for_row(matrix, 0, len(matrix) - 1, target)

        if row == -1:
            return False
        else:
            return self.search_for_target(matrix[row], 0, len(matrix[row]) - 1, target)

if __name__ == '__main__':
    sol = Solution()
    print(sol.searchMatrix([[-10,-8,-6,-4,-3],[0,2,3,4,5],[8,9,10,10,12]], 0))