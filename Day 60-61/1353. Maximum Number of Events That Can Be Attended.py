# 1353. Maximum Number of Events That Can Be Attended
'''

1. Input:
events: List of tuples representing events where each tuple is (start_time, end_time).
2. Initialize:
Create a defaultdict startToEnd to map each start time to a list of corresponding end times.
Initialize res to 0 (result variable).
Create a min-heap (q) to keep track of end times.
3. Populate Dictionary:
Iterate through each event in the input list and populate the startToEnd dictionary.
4. Sort Events:
Sort the events based on their start times.
5. Greedy Approach:
Iterate through all time points between the earliest start time and the latest end time.
For each time point (i):
Add the end times of events starting at i to the heap.
Remove events from the heap whose end times are less than i.
6. Attend Events:
If there are events in the heap and the earliest end time is greater than or equal to i:
Increment res.
Update the heap by removing the attended event.
7. Output:
Return the maximum number of non-overlapping events (res).


'''


import collections, heapq
class Solution:
    def maxEvents(self, events) -> int:
        if len(events) == 0:
            return 0

        startToEnd = collections.defaultdict(list)

        for start, end in events:
            startToEnd[start].append(end)

        res = 0
        q = []
        for i in range(min(events, key=lambda x: x[0])[0], max(events, key=lambda x: x[1])[1] + 1):
            for num in startToEnd[i]:
                heapq.heappush(q, num)

            while len(q) != 0 and q[0] < i:
                heapq.heappop(q)

            if len(q) != 0 and q[0] >= i:
                heapq.heappop(q)
                res += 1

        return res
