'''
Input: num = 1234
Output: 3412
Explanation: Swap the digit 3 with the digit 1, this results in the number 3214.
Swap the digit 2 with the digit 4, this results in the number 3412.
Note that there may be other sequences of swaps but it can be shown that 3412 is the largest possible number.
Also note that we may not swap the digit 4 with the digit 1 since they are of different parities.

Algorithm:

1. Convert the given integer num to a string t.
2. Separate the even and odd digits of t into two separate lists c1 and c2 using list comprehensions.
3. Sort both c1 and c2 in reverse order.
4. Initialize an empty string ans to store the final result.
5. Initialize two pointers p1 and p2 to 0.
6. Iterate through each character of the string t.
If the digit is even, append the p1-th element of c1 to the result ans and increment p1.
If the digit is odd, append the p2-th element of c2 to the result ans and increment p2.
7. Convert the final result ans to an integer and return it.


'''

class Solution:
    def largestInteger(self, num: int) -> int:
        t = str(num)
        c1 = [t[i] for i in range(len(t)) if int(t[i]) % 2 == 0]
        c2 = [t[i] for i in range(len(t)) if int(t[i]) % 2 == 1]
        c1.sort(reverse=True)
        c2.sort(reverse=True)
        ans = ''
        p1 = p2 = 0
        for i in range(len(t)):
            if int(t[i]) % 2 == 0:
                ans += c1[p1]
                p1 += 1
            else:
                ans += c2[p2]
                p2 += 1
        return int(ans)
