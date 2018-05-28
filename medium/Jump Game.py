class Solution:
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        curr_max = 0
        
        for i in range(len(nums)):
            if i > curr_max:
                return False
                
            if i + nums[i] > curr_max:
                curr_max = i + nums[i]
            print(curr_max)

        return True

if __name__ == '__main__':
    sol = Solution()
    print(sol.canJump([3,2,1,0,4]))