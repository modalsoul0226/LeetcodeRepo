# O(n) solution
class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = -(2 ** 32)
        temp = 0
        
        for i in nums:
            if temp < 0:
                temp = i
            else:
                temp += i
            
            if temp > res: res = temp
        
        return res
# class Solution:
#     def maxSubArray(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: int
#         """
#         if not nums or len(nums) == 0: return None

#         return self.findMax(nums, 0, len(nums) - 1)
    
#     def findMax(self, nums, start, end):
#         if start == end:
#             return nums[start]
        
#         mid = (start + end) / 2
#         left_max = self.findMax(nums, start, mid)
#         right_max = self.findMax(nums, mid + 1, end)
#         temp_max = left_max if left_max > right_max else right_max
        
#         max_sum = 0
#         curr_sum = 0
#         i = mid + 1
#         while i <= end:
#             curr_sum += nums[i]
#             if curr_sum > max_sum: max_sum = curr_sum
#             i += 1
        
#         i = mid - 1
#         curr_sum = max_sum
#         while i >= start:
#             curr_sum += nums[i]
#             if curr_sum > max_sum: max_sum = curr_sum
#             i -= 1

#         max_sum += nums[mid]

#         return max_sum if max_sum > temp_max else temp_max

if __name__ == '__main__':
    sol = Solution()
    # print(sol.maxSubArray([[8,-19,5,-4,20]]))
    print(sol.maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))