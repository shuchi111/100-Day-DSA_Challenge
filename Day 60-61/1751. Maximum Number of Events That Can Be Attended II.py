'''
1. Sort events: Sort the events based on their start times.
2. Define recursive function: Create a recursive function calc(i, kk) to explore attending or skipping events.
3. Base cases: If i reaches the end or kk becomes 0, return 0.
4. Calculate maximum value: Use recursion to find the maximum value:
Skip the current event: calc(i+1, kk).
Attend the current event: calc(j, kk-1) + events[i][2] (considering the next event).
5. Memoization: Utilize memoization (@cache) to store and reuse results.
6. Return result: Call calc(0, k) to get the maximum value considering the first event and k remaining events.
7. Output: Return the calculated maximum value.


This algorithm explores the event space, considering the trade-off between attending and skipping events, and uses memoization for optimization.

'''

class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        events.sort()
        @cache
        def calc(i, kk):
            if i == len(events) or kk == 0: return 0
            j = bisect_right(events, events[i][1], lo=i+1, key=lambda x: x[0])
            return max(calc(i+1, kk), calc(j, kk-1) + events[i][2])
        return calc(0, k)
