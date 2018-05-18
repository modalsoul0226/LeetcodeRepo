class Solution:
    def swap(self, nums, i, j):
        nums[i], nums[j] = nums[j], nums[i]
        
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        last_idx = len(nums) - 1
        i = 0
        
        while i <= last_idx:
            if nums[i] == val:
                self.swap(nums, i, last_idx)
                last_idx -= 1
            
            else: i += 1
        
        return last_idx + 1

if __name__ == '__main__':
    sol = Solution()
    list1 = [0,1,2,2,3,0,4,2]
    for i in range(sol.removeElement(list1, 2)):
        print('%d' % list1[i])