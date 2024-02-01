#1456. Maximum Number of Vowels in a Substring of Given Length
"""
Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.

Short Algorithm:

Sliding Window Approach:
1. Initialize a sliding window of size k with initial characters from the string.
2. Iterate through the string, updating the window by removing the leftmost character and adding the rightmost character at each step.
3. Calculate the running sum of vowel count differences using accumulate.
4. Find the maximum value in the accumulated result, representing the maximum number of vowels in any window of size k.

"""

class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        return max(accumulate(
            zip(chain(repeat('z', k), s), s),
            lambda a, x: a - (x[0] in 'aeiou') + (x[1] in 'aeiou'),
            initial=0,
        ))

