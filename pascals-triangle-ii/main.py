class Solution:
    # @return a list of integers
    def getRow(self, rowIndex):
        if rowIndex == 0:return [1]
        ret = [1]
        tmp = []
        for i in xrange(rowIndex):
            tmp += [1]
            for l in xrange(len(ret) - 1):
                tmp += [ret[l] + ret[l + 1]]
            tmp += [1]
            ret = tmp
            tmp = []
        return ret

for i in xrange(10):
    print i,Solution().getRow(i)
