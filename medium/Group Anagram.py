class Solution:
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        res = []
        anagram_list = []
        
        for item in strs:
            char_dict = {} 
            for char in item:
                if char not in char_dict:
                    char_dict[char] = 1
                else:
                    char_dict[char] += 1
            
            if char_dict not in anagram_list:
                anagram_list.append(char_dict)
                res.append([item])
            else:
                res[anagram_list.index(char_dict)].append(item)
        
        return res

if __name__ == '__main__':
    sol = Solution()
    print(sol.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))