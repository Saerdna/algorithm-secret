class MinStack:
    # @param x, an integer
    # @return an integer
    def __init__(self):
        self.que = []
        self.min_que = []
    def push(self, x):
        if len(self.que) == 0:
            self.que += [x]
            self.min_que += [[x, 1]]
        else:
            minInt = self.getMin()
            if x < minInt:
                self.min_que += [[x, 1]]
            else:
                self.min_que[-1][1] += 1
    # @return nothing
    def pop(self):
        self.que.pop()
        if self.min_que[-1][1] > 1:
            self.min_que[-1][1] -= 1
        else:
            self.min_que.pop()

    # @return an integer
    def top(self):
        return self.que[-1]

    # @return an integer
    def getMin(self):
        return self.min_que[-1][0]
