class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        start = end = 0
        prev, count = None, 0
        
        while end < len(nums):
            if nums[end] != prev:
                prev = nums[end]
                count = 1
            else:
                count += 1
                
            if count <= 2:
                nums[start], nums[end] = nums[end], nums[start]
                start += 1
            end += 1
        
        return start

if __name__ == '__main__':
    sol = Solution()
    nums, res = [0,0,1,1,1,1,2,3,3], []
    for i in range(sol.removeDuplicates(nums)): res.append(nums[i])
    print(res)
