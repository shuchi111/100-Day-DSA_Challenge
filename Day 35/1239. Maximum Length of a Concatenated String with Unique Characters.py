#1239. Maximum Length of a Concatenated String with Unique Characters
# Bit manipulation
"""
Example 1:


Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.


1. Function maxLength(a):
2.   Define a recursive helper function f(i, s):
3.     Base Case:
         - If i reaches the length of a, return the length of the set s.
4.     Recursive Exploration:
         - Call f(i+1, s) to explore the case where the current string is not included.
5.     Include Current String (a[i]):
         - Create a new set g by taking the union of s and the set of characters in the current string a[i].
         - If len(g) is equal to the sum of the lengths of s and a[i], update the result by recursively calling f(i+1, g).
6.     Return the maximum length obtained by considering or excluding the current string.
7.   Call f(0, set()) in the main function.
8.   Return the result obtained from the recursive exploration.


Time Complexity:
The time complexity of this recursive solution is exponential, O(2^n), where n is the length of the list a.

"""
class Solution:
    def maxLength(self, a: List[str]) -> int:
        def f(i, s):
            if i == len(a):
                return len(s)

            result = f(i+1, s)
            g = s | {*a[i]}
            if len(g) == len(s) + len(a[i]):
                result = max(result, f(i+1, g))

            return result
        
        return f(0, set())

  
