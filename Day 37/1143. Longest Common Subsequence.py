#1143. Longest Common Subsequence
"""
Algorithm:

1. Initialize variables m and n with the lengths of text1 and text2, respectively.
2. Initialize a 2D array l of size (m+1) x (n+1) filled with zeros.
3. Iterate through the range (1, m+1) and (1, n+1) with two nested loops.
If text1[i-1] is equal to text2[j-1], set l[i][j] to l[i-1][j-1] + 1.
Otherwise, set l[i][j] to max(l[i-1][j], l[i][j-1]).
4. The final element l[m][n] contains the length of the LCS.
5. Return l[m][n].

"""
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        # Get the lengths of the input strings
        m, n = len(text1), len(text2)
        
        # Initialize a 2D array l filled with zeros
        l = []
        for i in range(m+1):
            v = [0]*(n+1)
            l.append(v)

        # Iterate through the characters of text1 and text2
        for i in range(1, m+1):
            for j in range(1, n+1):
                # Update the length of LCS based on character equality
                if text1[i-1] == text2[j-1]:
                    l[i][j] = l[i-1][j-1] + 1
                
