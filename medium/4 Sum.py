class Solution:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        if len(nums) < 4:
            return None
        
        nums.sort()
        sum_table, num_count = {}, {}
        res, res_set = [], set()
        
        for i in nums:
            if i in num_count: num_count[i] += 1
            else: num_count[i] = 1

        for i in range(len(nums) - 1):
            for j in range(i + 1, len(nums)):
                two_sum = nums[i] + nums[j]
                    
                if target - two_sum in sum_table:
                    for each in sum_table[target - two_sum]:
                        temp = [nums[i], nums[j]]

                        # print(each)
                        # print(temp)
                        # print('\n')
                        temp.extend(each)
                        if (temp.count(nums[i]) > num_count[nums[i]]) or (temp.count(nums[j]) > num_count[nums[j]]): continue
                        temp.sort()
                        key = ','.join(map(lambda x: str(x), temp))
                        
                        if key not in res_set:
                            res.append(temp)
                            res_set.add(key)
                
                if two_sum in sum_table:
                    sum_table[two_sum].append([nums[i], nums[j]])
                else:
                    sum_table[two_sum] = [[nums[i], nums[j]]]

        return res

if __name__ == '__main__':
    sol = Solution()
    print(sol.fourSum([-2, -1, 0, 0, 1, 2], 0))