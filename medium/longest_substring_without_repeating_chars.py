class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        
        i = j = 0
        length = res = 0
        table = {}
        
        
        while j != len(s):
            
            if s[j] in table:
                res = length if length > res else res
                
                while i != table[s[j]]:
                    del table[s[i]]
                    i += 1
                
                table[s[i]] = j
                i += 1
                length = j - i + 1
            else:
                table[s[j]] = j
                length += 1
            
            j += 1
                
        res = length if length > res else res
        return res        