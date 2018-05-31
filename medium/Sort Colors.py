class Solution:
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        k, i, j = 0, 0, len(nums) - 1

        while k <= j:
            print("k: %d i: %d j: %d" % (k, i, j))
            print(nums)
            if nums[k] == 2:
                nums[k], nums[j] = nums[j], nums[k]
                j -= 1
            elif nums[k] == 0:
                nums[k], nums[i] = nums[i], nums[k]
                i += 1
                k += 1
            else:
                k += 1
            
    

if __name__ == '__main__':
    sol = Solution()
    nums = [2,0,2,1,1,0]
    sol.sortColors(nums)