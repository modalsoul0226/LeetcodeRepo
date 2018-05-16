class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        list_one = ['I', 'X', 'C', 'M']
        list_five = ['V', 'L', 'D']
        res = ''
        d_num = 0
        
        while num:
            last_d = num % 10
            
            remainder = last_d % 5
            power = last_d / 5
            
            if last_d == 4:
                res = list_one[d_num] + list_five[d_num] + res
            elif last_d == 9:
                res = list_one[d_num] + list_one[d_num + 1] + res
            else:
                res = list_one[d_num] * remainder + res
                if power:
                    res = list_five[d_num] + res
                
            d_num += 1
            num /= 10
        
        return res

if __name__ == '__main__':
    sol = Solution()
    print(sol.intToRoman(3) + '\n')
    print(sol.intToRoman(4) + '\n')
    print(sol.intToRoman(9) + '\n')
    print(sol.intToRoman(58) + '\n')
    print(sol.intToRoman(1994) + '\n')