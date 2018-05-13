class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
# Solution 1:
#         table = {x: [0, nums.index(x)] for x in nums}
#         idx = 0
        
#         for i in nums:
#             res = table.get(target - i)
            
#             if res and res[0]: 
#                 return [res[1], idx]
            
#             else:
#                 table[i][0] = 1
#                 table[i][1] = idx
                
#             idx += 1
  
# Solution 2:
#         table = {x: nums.index(x) for x in nums}
        
#         for i in range(len(nums)):
#             if (table.get(target - nums[i]) is not None) and (table[target - nums[i]] != i):
#                 return [table[target - nums[i]], i]

        # Solution 3:
        table = {}
        
        for i in range(len(nums)):
            if target - nums[i] in table:
                return [table[target - nums[i]], i]
            else:
                table[nums[i]] = i