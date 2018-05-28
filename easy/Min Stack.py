class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.min = 2 ** 31 - 1

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        if not self.stack: self.min = x
            
        self.stack.append(x - self.min)
        self.min = x if x < self.min else self.min
        
    def pop(self):
        """
        :rtype: void
        """
        if not self.stack: return
        
        x = self.stack.pop()
        self.min = self.min - x if x < 0 else self.min

    def top(self):
        """
        :rtype: int
        """
        if not self.stack: return
        
        if self.stack[-1] < 0:
            return self.min
        return self.min + self.stack[-1]

    def getMin(self):
        """
        :rtype: int
        """
        if not self.stack: return
        
        return self.min