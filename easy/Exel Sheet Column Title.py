class Solution:
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        res = ''
        ab_list = 'ZABCDEFGHIJKLMNOPQRSTUVWXY'
        
        while n:
            idx = n % 26
            res = ab_list[idx] + res
            
            if n % 26 == 0: n = n / 26 - 1
            else: n /= 26
        
        return res

if __name__ == '__main__':
    sol = Solution()
    a = 26 ** 3
    print(sol.convertToTitle(a))