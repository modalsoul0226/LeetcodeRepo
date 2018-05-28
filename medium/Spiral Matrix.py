class Solution:
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix: return []

        res = []
        up_left, down_right = [0, 0], [len(matrix) - 1, len(matrix[0]) - 1] 
        
        while up_left[0] <= down_right[0] and up_left[1] <= down_right[1]:
            print('up left: [%d, %d]' % (up_left[0], up_left[1]))
            print('down right: [%d, %d]' % (down_right[0], down_right[1]))

            for i in range(down_right[1] - up_left[1] + 1):
                res.append(matrix[up_left[0]][up_left[1] + i])
            
            if up_left[0] == down_right[0]: break
            
            for i in range(1, down_right[0] - up_left[0] + 1):
                res.append(matrix[up_left[0] + i][down_right[1]])
            
            if up_left[1] == down_right[1]: break

            for i in range(down_right[1] - 1, up_left[1], -1):
                res.append(matrix[down_right[0]][i])
            
            for i in range(down_right[0], up_left[0], -1):
                res.append(matrix[i][up_left[1]])

            up_left[0] += 1
            up_left[1] += 1
            down_right[0] -= 1
            down_right[1] -= 1

        return res

if __name__ == '__main__':
    sol = Solution()
    print(sol.spiralOrder([
                        [1,2,3,4], 
                        [5,6,7,8],
                        [9,10,11,12],
                        [13,14,15,16]
                        ]))