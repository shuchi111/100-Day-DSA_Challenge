#232. Implement Queue using Stacks
class MyQueue:

    def __init__(self):
        self.q=[]

    def push(self, x: int) -> None:
        self.q.append(x)
        for i in range(len(self.q)-1):
            self.q.append(self.q.pop(0))

    def pop(self) -> int:
        return self.q.pop(len(self.q)-1)

    def peek(self) -> int:
        return self.q[len(self.q)-1]

    def empty(self) -> bool:
        if len(self.q)==0:
            return True
        return False


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
