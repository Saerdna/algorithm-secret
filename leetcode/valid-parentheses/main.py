class Solution:
    # @return a boolean
    def isValid(self, s):
        arr = []
        for i in xrange(len(s)):
            if s[i] in ['(', '{', '[']:
                arr.append(s[i])
                continue
            if len(arr) == 0:return False
            if s[i] == ')' and arr[-1] == '(':
                arr.pop()
                continue
            elif s[i] == '}' and arr[-1] == '{':
                arr.pop()
                continue
            elif s[i] == ']' and arr[-1] == '[':
                arr.pop()
                continue
            arr.append(s[i])

        return True if len(arr) == 0 else False

sol = Solution()
print sol.isValid("[]")
print sol.isValid("[{]}")
print sol.isValid("[{()}]")
