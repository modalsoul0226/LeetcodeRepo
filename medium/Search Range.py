class Solution:
    def search_end(self, nums, target):
        end = -1
        i, j = 0, len(nums) - 1
        
        while i <= j:
            mid = (i + j) // 2
            
            if target == nums[mid]:
                end = mid
                i = mid + 1
            elif target < nums[mid]:
                j = mid - 1
            else:
                i = mid + 1
        
        return end
    
    def search_start(self, nums, target):
        start = -1
        i, j = 0, len(nums) - 1
        
        while i <= j:
            mid = (i + j) // 2
            
            if target == nums[mid]:
                start = mid
                j = mid - 1
            elif target < nums[mid]:
                j = mid - 1
            else:
                i = mid + 1
        
        return start
        
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if not nums or len(nums) == 0 or target is None:
            return [-1, -1]
        
        start, end = self.search_start(nums, target), self.search_end(nums, target)
        return [start, end]

if __name__ == '__main__':
    sol = Solution()
    print(sol.searchRange([0, 0, 0, 1, 2, 3], 0))