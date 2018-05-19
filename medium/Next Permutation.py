class Solution:
    def swap(self, nums, i, j):
        if i == -1: return
        
        nums[i], nums[j] = nums[j], nums[i]
    
    def sort(self, nums, i, j):
        while j > i:
            self.swap(nums, i, j)
            i += 1
            j -= 1
    
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        length = len(nums)
        if not nums or length < 2: return
        
        start, end = -1, length - 1
        
        for i in range(length - 1, -1, -1):
            if i <= start: break
            
            for j in range(i - 1, -1, -1):
                if j <= start: break
                    
                if nums[j] < nums[i]:
                    if j > start: start, end = j, i
                    break
        
        self.swap(nums, start, end)
        self.sort(nums, start + 1, length - 1)

if __name__ == '__main__':
    sol = Solution()
    test_list = [2, 3, 1]
    sol.nextPermutation(test_list)
    print(test_list)