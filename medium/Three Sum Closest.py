class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        
        closest_sum = None
        
        for i in range(len(nums) - 2):
            diff = target - nums[i]
            print('i: %d' % i)
            j, k = i + 1, len(nums) - 1
            
            while (j < k):
                if closest_sum is not None: 
                    print('i: %d j: %d k: %d diff: %d closest_sum: %d\n' % (nums[i], nums[j], nums[k], diff, closest_sum))
                if (closest_sum is None) or (abs(diff - nums[j] - nums[k]) < abs(target - closest_sum)): 
                    closest_sum = nums[i] + nums[j] + nums[k]
                    # print('%d %d %d %d\n' % (nums[i], nums[j], nums[k], closest_sum))
                
                if (nums[j] + nums[k]) < diff: j += 1
                elif (nums[j] + nums[k]) > diff: k-= 1
                else: return closest_sum
        
        return closest_sum

if __name__ == '__main__':
    sol = Solution() # -3 0 1 2
    print(sol.threeSumClosest([0,2,1,-3], 1))