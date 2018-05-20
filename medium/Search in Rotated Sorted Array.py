class Solution:
    def two_search(self, nums, start, end, target):
        if nums[start] == target:
            return start
        elif nums[end] == target:
            return end
        else:
            return -1
    
    def bin_search(self, nums, start, end, target):
        if end - start <= 1:
            return self.two_search(nums, start, end, target)
        
        mid = (start + end) // 2

        if nums[mid] == target:
            return mid
        
        
        if (nums[mid - 1] > nums[mid] and target < nums[mid]) or (nums[mid + 1] < nums[mid] and target > nums[mid]):
            return -1
        
        if nums[start] < nums[mid] < nums[end]:
            if target > nums[mid]:
                return self.bin_search(nums, mid + 1, end, target)
            else:
                return self.bin_search(nums, start, mid - 1, target)
        
        elif nums[end] < nums[start] < nums[mid]:
            if nums[start] <= target < nums[mid]:
                return self.bin_search(nums, start, mid - 1, target)
            else:
                return self.bin_search(nums, mid + 1, end, target)
        
        else:
            if nums[mid] < target <= nums[end]:
                return self.bin_search(nums, mid + 1, end, target)
            else:
                return self.bin_search(nums, start, mid - 1, target)

    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        return self.bin_search(nums, 0, len(nums) - 1, target)

if __name__ == '__main__':
    sol = Solution()
    print(sol.search([3,4,5,6,1,2], 5))