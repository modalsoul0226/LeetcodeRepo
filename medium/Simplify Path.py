class Solution:
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        stack, buffer = [], ''
        
        for i in range(len(path)):
            if path[i] != '/':
                buffer += path[i]
            else:
                if buffer: stack.append(buffer)
                buffer = ''
        if buffer: stack.append(buffer)

        res = []
        for i in stack:
            if i == '.':
                continue
            elif i == '..':
                if res: res.pop()
            else:
                res.append(i)
        
        ans = '' if res else '/'
        for i in res: ans += '/' + i
        return ans

if __name__ == '__main__':
    sol = Solution()
    print(sol.simplifyPath('/.//.../c'))