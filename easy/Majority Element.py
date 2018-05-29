class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cut = len(nums) // 2
        dict = {}
        for num in nums:
            if num in dict:
                dict[num] += 1
                if dict[num] > cut: return num
            else:
                dict[num] = 1

if __name__ == '__main__':
    sol = Solution()
    print(sol.majorityElement([2, 2, 1, 1, 1, 2, 2]))