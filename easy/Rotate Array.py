class Solution:
    def bubble_down(self, nums, start, i):
        while i > start:
            nums[i - 1], nums[i] = nums[i], nums[i - 1]
            i -= 1
    
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        k %= len(nums)
        for i in range(len(nums) - k, len(nums)):
            self.bubble_down(nums, i - (len(nums) - k), i)

if __name__ == '__main__':
    sol = Solution()
    nums = [1,2,3,4,5,6,7]
    sol.rotate(nums, 5)
    print(nums)