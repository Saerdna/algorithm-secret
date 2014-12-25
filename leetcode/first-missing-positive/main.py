class Solution:
    # @param A, a list of integers
    # @return an integer
    def firstMissingPositive(self, A):
        for i in xrange(len(A)):
            while A[i] != i + 1:
                if A[i] >= 1 and A[i] <= len(A) and A[i] != A[A[i] - 1]:
                    tmp = A[A[i] - 1]
                    A[A[i] - 1] = A[i]
                    A[i] = tmp
                else:
                    break
        for i in xrange(len(A)):
            if A[i] != i + 1:
                return i + 1
        return len(A) + 1
