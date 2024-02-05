'''Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

Example 1:

Input: s = "leetcode"
Output: 0



The algorithm is using a Brute Force Approach with the aid of the Counter class from the collections module. Here's a breakdown:

Character Counts:
The algorithm utilizes the Counter class to count the occurrences of each character in the input string s. This step creates a dictionary-like object (char_counts) with characters as keys and their counts as values.

Iterative Search for Uniqueness:
It then iterates through the string s using enumeration to keep track of both the index (i) and the character.
For each character, it checks if the count of that character in char_counts is equal to 1. This check identifies the first unique character in the string.

Return Result:
If a unique character is found during the iteration, the algorithm returns the index of that character.
If no unique character is found after the complete iteration, the algorithm returns -1, indicating that there are no unique characters in the string.

'''

class Solution:
    def firstUniqChar(self, s: str) -> int:
        
        
        char_counts = Counter(s)
    
        for i, char in enumerate(s):
            if char_counts[char] == 1:
                return i
        
        return -1
        
        
