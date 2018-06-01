class Solution:
    def bin_search(self, nums, start, end, target):
        mid = (start + end) // 2
        if nums[mid] == target: 
            return True
        elif start == end:
            return False
        
        if nums[start] <= nums[mid] <= nums[end]:
            if nums[mid] < target: return self.bin_search(nums, mid + 1, end, target)
            else: return self.bin_search(nums, start, mid, target)
        
        elif nums[mid] <= nums[end]:
            res = self.bin_search(nums, start, mid, target)
            if nums[mid] > target: return res
            else: return res or self.bin_search(nums, mid + 1, end, target)
        
        else:
            res = self.bin_search(nums, mid + 1, end, target)
            if nums[mid] < target: return res
            else: return res or self.bin_search(nums, start, mid, target)
    
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        return self.bin_search(nums, 0, len(nums) - 1, target)