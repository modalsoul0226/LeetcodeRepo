class Solution:
    def search(self, board, path, row, col, word):
        # print(word)
        # print(path)
        # print(row, col)
        
        if not word:
            return True
        elif board[row][col] != word[0]:
            return False
        else:
            path[row][col] = 1
            if len(word) == 1: return True
        res = False
        if row > 0 and not path[row - 1][col]:
            res = self.search(board, path, row - 1, col, word[1:])
        if not res and row + 1 < len(board) and not path[row + 1][col]:
            res = self.search(board, path, row + 1, col, word[1:])
        if not res and col > 0 and not path[row][col - 1]:
            res = self.search(board, path, row, col - 1, word[1:])
        if not res and col + 1 < len(board[row]) and not path[row][col + 1]:
            res = self.search(board, path, row, col + 1, word[1:])
        
        if not res: path[row][col] = 0
        return res
        
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        if not board or word is None:
            return False
        
        for row in range(len(board)):
            if not board[row]:
                return False
            
            for col in range(len(board[row])):
                if board[row][col] == word[0]:
                    path = [[0 for _ in range(len(board[row]))] for _ in range(len(board))]
                    if self.search(board, path, row, col, word): return True
        
        return False

if __name__ == '__main__':
    sol = Solution()
    print(sol.exist([
  ['A','B','C','E'],
  ['S','F','E','S'],
  ['A','D','E','E']
], 'CESEEEFS'))