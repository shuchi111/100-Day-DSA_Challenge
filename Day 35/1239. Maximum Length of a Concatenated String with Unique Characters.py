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
        # Recursive helper function to explore all possible combinations
        def f(i, s):
            # Base Case: If i reaches the length of a, return the length of the set s
            if i == len(a):
                return len(s)

            # Recursive Exploration: Call f(i+1, s) to explore the case where the current string is not included
            result = f(i+1, s)

            # Include Current String (a[i]):
            # Create a new set g by taking the union of s and the set of characters in the current string a[i]
            g = s | {*a[i]}

            # If len(g) is equal to the sum of the lengths of s and a[i], update the result
            if len(g) == len(s) + len(a[i]):
                # Recursively call f(i+1, g) to explore the case where the current string is included
                result = max(result, f(i+1, g))

            return result
        
        # Call the recursive helper function with initial parameters (starting from index 0 and an empty set)
        return f(0, set())


  
