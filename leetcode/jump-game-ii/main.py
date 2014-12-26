class Solution:
    # @param A, a list of integers
    # @return an integer
    def jump(self, A):
        step = {}
        step[1] = A[0]
        idx = 1
        i = 1
        while i < len(A):
            if i <= step[idx]:
                step[idx + 1] = max(step.get(idx + 1, 0), i + A[i])
            else:
               step[idx + 1] = max(step.get(idx + 1, 0) , step[idx] + A[i])
               idx += 1
            i += 1
        print step
        return idx
            
sol = Solution()
print sol.jump([1,1,1,2,1])
