class Solution:
    # @return a string
    def convert(self, s, nRows):
        if nRows == 1:return s
        r = 0
        c = 0
        for i in xrange(len(s)):
            if c % (nRows - 1) == 0:
                if r == nRows - 1:
                    r -= 1
                    c += 1
                else:
                    r += 1
            else:
                c += 1
                r -= 1
        c += 2 
        mat = [[''] * c for r in xrange(nRows)]
        r = 0
        c = 0
        for i in xrange(len(s)):
            mat[r][c] = s[i]
            if c % (nRows - 1) == 0:
                if r == nRows - 1:
                    r -= 1
                    c += 1
                else:
                    r += 1
            else:
                c += 1
                r -= 1
        ret = ''
        for r in xrange(nRows):
            ret += ''.join(mat[r])
        return ret

print Solution().convert("PAYPALISHIRING", 3)


