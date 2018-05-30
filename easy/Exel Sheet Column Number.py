class Solution:
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        count, res = 0, 0
        
        for char in s[::-1]:
            res += (26 ** count) * (ord(char) - ord('A') + 1)
            count += 1
        
        return res

if __name__ == '__main__':
    sol = Solution()
    print(sol.titleToNumber('AB'))