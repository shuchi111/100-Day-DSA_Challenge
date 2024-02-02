# 1291. Sequential Digits
'''
Example 1:

Input: low = 100, high = 300
Output: [123,234]
'''

class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        res = []
        dq = collections.deque(list(range(1, 10)))
        while dq:
            n = len(dq)
            for _ in range(n):
                num = dq.popleft()
                if num > high: continue
                if low <= num <= high: res.append(num)
                last_digit = num % 10
                if last_digit < 9: dq.append(num * 10 + last_digit + 1)
            
        return res
