class Solution:
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        res = {}
        
        for item in strs:
            sorted_chars = ''.join(sorted(item))
            
            if sorted_chars not in res:
                res[sorted_chars] = [item]
            else:
                res[sorted_chars].append(item)
        
        return res.values()

if __name__ == '__main__':
    sol = Solution()
    print(sol.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))