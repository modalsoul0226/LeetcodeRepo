class Solution:
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if not nums or len(nums) == 0:
            return []
        elif len(nums) == 1:
            return [nums]
        else:
            res = []
            temp_res = self.permute(nums[1:])
            for each in temp_res:
                for i in range(len(each) + 1):
                    temp = each[:i] + [nums[0]] + each[i:]
                    print(temp)
                    res.append(temp)
            
            return res

# A better solution:
# class Solution(object):
#     def permute(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: List[List[int]]
#         """
#         if not nums:
#             return None
#         stack=[[[nums[0]],0]]
#         i=0
#         res=[]
        
#         while(stack):
#             arr,index=stack.pop()
#             if index==len(nums)-1:
#                 res.append(arr)
#             else:           
#                 for i in range(len(arr)+1):
#                     newPermutation=arr[:i]+ [nums[index+1]] + arr[i:]
#                     print(newPermutation)
#                     stack.append([newPermutation,index+1])
                    
#         return res

if __name__ == '__main__':
    sol = Solution()
    print('\n')
    print(sol.permute([1, 2, 3]))