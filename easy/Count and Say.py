class Solution:
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n == 1:
            return '1'
        else:
            res = ''
            string = self.countAndSay(n - 1)
            
            count = 0
            for i in range(len(string)):
                count += 1
                
                if i == len(string) - 1 or string[i + 1] != string[i]:
                    res += str(count) + string[i]
                    count = 0
            
            return res

if __name__ == '__main__':
    sol = Solution()
    print(sol.countAndSay(1))
    print(sol.countAndSay(2))
    print(sol.countAndSay(3))
    print(sol.countAndSay(4))
    print(sol.countAndSay(5))