# Solution
from collections import Counter

class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if len(word1) != len(word2):
            return False

        count1 = Counter(word1)
        count2 = Counter(word2)

        if set(count1.keys()) != set(count2.keys()):
            return False

        if sorted(count1.values()) != sorted(count2.values()):
            return False

        return True


"""
Algorithm:

1. Check if the lengths of word1 and word2 are equal. If not, return False.
2. Use Counter to count the occurrences of each character in both word1 and word2 (count1 and count2).
3. Check if the sets of keys in count1 and count2 are equal. If not, return False (the sets of characters should be the same in both words).
4. Check if the sorted lists of values in count1 and count2 are equal. If not, return False (the frequencies of characters should be the same in both words).
5. If all the conditions are satisfied, return True.



Example 1:

Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"


"""
