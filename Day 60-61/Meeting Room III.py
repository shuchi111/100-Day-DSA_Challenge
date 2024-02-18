# Meeting Room III
'''
Algorithm:

1. Initialize two lists r and c of size n to represent the rooms' end times and the counter for each room,
respectively, with all elements initially set to 0.
2. Iterate through the sorted list m representing the booking intervals:
For each booking interval [s, e], find an available room with an end time less than or equal to s.
If found, update the end time of the room to e and increment the counter for that room.
If not found, find the room with the minimum end time and update its end time to e and increment its counter.
3. Return the index of the room with the maximum counter value.


Time Complexity:
The time complexity of the algorithm is O(n * log(n)), where n is the number of booking intervals. 
This is due to the sorting of the booking intervals.

Space Complexity:
The space complexity is O(n), where n is the number of rooms, as it requires two lists of size n (r and c).

'''

class Solution:
    def mostBooked(self, n: int, m: List[List[int]]) -> int:
        r, c = [0]*n, [0]*n # rooms, counter
        for s, e in sorted(m):
            find = 0
            for i,f in enumerate(r):
                if f <= s:
                    r[i] = e
                    c[i] += 1
                    find = 1
                    break

            if not find:
                q = r.index(min(r))
                r[q] += e-s
                c[q] += 1

        return c.index(max(c))

