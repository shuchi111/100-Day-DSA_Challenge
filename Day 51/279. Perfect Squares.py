'''
Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.


Algorithm Overview:

Initialize an array dp to store the minimum number of perfect squares needed for each number up to n.
Set dp[0] to 0, as zero requires 0 perfect squares.
Iterate through each number from 1 to n.
For each number i, calculate the minimum number of perfect squares needed by considering all possible perfect squares less than or equal to i.
Update the dp array with the minimum value.
Return dp[n], which represents the minimum number of perfect squares needed for the given input n.



'''

class Solution:
    def numSquares(self, n: int) -> int:
        # Initialize an array to store the minimum number of perfect squares needed for each number up to n
        dp = [float('inf')] * (n + 1)
        
        # Zero is the only number that requires 0 perfect squares
        dp[0] = 0
        
        # Iterate through each number from 1 to n
        for i in range(1, n + 1):
            # For each i, calculate the minimum number of perfect squares needed
            dp[i] = min(dp[i - j * j] + 1 for j in range(1, int(i**0.5) + 1))
        
        # The result is the minimum number of perfect squares needed for the given n
        return dp[n]
