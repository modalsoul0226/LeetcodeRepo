class Solution:
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        d_list = [0 for i in range(len(num1) + len(num2))]
        c_bit = 0
        
        if len(num1) < len(num2):
            num1, num2 = num2, num1
            
        for j in range(len(num2) - 1, -1, -1):
            for i in range(len(num1) - 1, -1, -1):
                product = int(num2[j]) * int(num1[i])
                
                sum = product + d_list[i + j + 1]
                d_1 = sum % 10
                sum = sum // 10 + d_list[i + j] + c_bit
                d_2 = sum % 10
                c_bit = sum // 10


                d_list[i + j + 1] = d_1
                d_list[i + j] = d_2
                
                # temp = ''
                # for i in range(len(d_list)):
                #     temp += str(d_list[i])
                # print(temp)

        res = ''
        flag = 1
        for i in range(len(d_list)):
            if i == 0 and d_list[i] == 0: continue
            else:
                res += str(d_list[i])
                if d_list[i] != 0: flag = 0
        
        if flag:
            return 0
        else:
            return res

if __name__ == '__main__':
    sol = Solution()
    print(sol.multiply('9999999999999999999999999999999999999999999999999999999', '99999999999999999999999999999999999999999999999999999999999999'))