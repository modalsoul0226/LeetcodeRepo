class Solution:
    def check_row(self, board, start):
        table = set()
        
        for i in range(9):
            num = board[start][i]
            if num == '.': 
                continue
            if int(num) in table:
                return False
            table.add(int(num))
        
        return True
    
    def check_col(self, board, start):
        table = set()
        
        for i in range(9):
            num = board[i][start]
            if num == '.':
                continue
            if int(num) in table:
                return False
            table.add(int(num))
        
        return True
    
    def check_blk(self, board, start):
        table = set()
        
        for i in range(3):
            for j in range(3):
                num = board[start[0] + i][start[1] + j]
                if num == '.':
                    continue
                if int(num) in table:
                    return False
                table.add(int(num))
        
        return True
    
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        for i in range(9):
            if not self.check_row(board, i) or not self.check_col(board, i):
                return False
        
        for i in range(3):
            for j in range(3):
                if not self.check_blk(board, [3 * i, 3 * j]):
                    return False
        
        return True
    
if __name__ == '__main__':
    sol = Solution()
#     print(sol.isValidSudoku([
#   ["5","3",".",".","7",".",".",".","."],
#   ["6",".",".","1","9","5",".",".","."],
#   [".","9","8",".",".",".",".","6","."],
#   ["8",".",".",".","6",".",".",".","3"],
#   ["4",".",".","8",".","3",".",".","1"],
#   ["7",".",".",".","2",".",".",".","6"],
#   [".","6",".",".",".",".","2","8","."],
#   [".",".",".","4","1","9",".",".","5"],
#   [".",".",".",".","8",".",".","7","9"]
# ]))
    print(sol.isValidSudoku([
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]))