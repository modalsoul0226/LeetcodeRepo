class Solution:
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n <= 0:
            return False
        elif n == 1:
            return True
        else:
            table = set()
            while (n != 1):
                temp = 0
                while (n):
                    temp += (n % 10) ** 2
                    n /= 10
                n = temp
                
                if n in table: return False
                else: table.add(n)
            
            return True

if __name__ == '__main__':
    sol = Solution()
    print(sol.isHappy(2))