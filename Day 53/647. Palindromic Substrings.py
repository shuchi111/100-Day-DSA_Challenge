'''

The problem is to count the number of palindromic substrings in the given string s. A straightforward approach is to iterate over all possible substrings and check if each substring is a palindrome.

Nested Loop Iteration:
Use two nested loops to iterate over all possible pairs of indices (i, j), where i is the starting index and j is the ending index of the substring.
The outer loop (for i in range(len(s))) iterates over all possible starting indices.
The inner loop (for j in range(i+1, len(s)+1)) iterates over all possible ending indices, ensuring that j is greater than i.

Palindrome Check:
For each pair of indices (i, j), extract the substring s[i:j].
Check if the substring is a palindrome by comparing it with its reverse (s[i:j][::-1]).
If the substring is a palindrome, increment the count variable.

Return Result:
After completing the nested loops, return the final count, which represents the total number of palindromic substrings in the given string.

'''

class Solution:
    def countSubstrings(self, s: str) -> int:
        count = 0
        for i in range(len(s)):
            for j in range(i+1,len(s)+1):
                if s[i:j] == s[i:j][::-1]:
                    count += 1
        return count
