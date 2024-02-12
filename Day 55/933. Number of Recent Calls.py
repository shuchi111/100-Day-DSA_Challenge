'''

Algorithm: RecentCounter
The goal of this code is to implement a class RecentCounter that keeps track of the number of requests made within the last 3000 milliseconds.
The ping method is used to add a new request timestamp t and return the number of requests made in the last 3000 milliseconds.

Initialization:
The __init__ method initializes an instance of the class with an empty deque (self.dq) to store the timestamps.

Ping Method:
The ping method takes a timestamp t as an argument.
Append the new timestamp t to the deque to represent the latest request.
While the deque is not empty and the front element of the deque is earlier than t - 3000 (outside the 3000 milliseconds window), remove elements from the front of the deque.
Return the current length of the deque, representing the number of requests within the last 3000 milliseconds.

'''


class RecentCounter:

    def __init__(self):
        self.dq = deque()
        

    def ping(self, t: int) -> int:
        self.dq.append(t)
        while self.dq and self.dq[0] <t-3000:
            self.dq.popleft()
        return len(self.dq)
