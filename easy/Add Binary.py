class Solution:
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        if len(a) < len(b): a, b = b, a
        
        res = ''
        c_bit = 0
        
        for i in range(len(a)):
            curr_sum = 0
            
            if i >= len(b):
                curr_sum = int(a[len(a) - 1 - i]) + c_bit
            else:
                curr_sum = int(a[len(a) - 1 - i]) + int(b[len(b) - 1 - i]) + c_bit
            
            res = str(curr_sum % 2) + res
            c_bit = curr_sum / 2
        
        if c_bit:
            res = '1' + res
        return res

if __name__ == '__main__':
    sol = Solution()
    print(sol.addBinary('11', '1'))
    print(sol.addBinary('1010', '1011'))