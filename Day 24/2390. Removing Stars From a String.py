"""Example 1:

Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".




Algorithm:

1. Initialize an empty list ans to store the characters of the final string.
2. Iterate through each character i in the input string s.
If i is equal to '*', remove the last character from ans (if ans is not empty).
Otherwise, append i to ans.
3. Return the string formed by joining the characters in ans.
"""

#solution
class Solution:
    def removeStars(self, s: str) -> str:
        ans=[]
        for i in s:
            if i=='*':
                ans.pop()
            else:
                ans+=[i]
        return "".join(ans)
