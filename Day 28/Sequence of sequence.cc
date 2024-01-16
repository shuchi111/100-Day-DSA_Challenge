//Sequence of sequence
/*
Example 1:

Input: 
m = 10
n = 4
Output: 
4
Explaination: 
There should be n elements and 
value of last element should be at-most m. 
The sequences are {1, 2, 4, 8}, {1, 2, 4, 9}, 
{1, 2, 4, 10}, {1, 2, 5, 10}.


Algorithm:

1. Initialization:
Create a 2D array dp of size n x (m + 1) and initialize all elements to 0.

2. Base Case:
Set the last row (n - 1) of dp to 1. This represents the base case where there is only one way to reach each element in the last row.

3. Dynamic Programming Loop:
Iterate from the second last row (n - 2) to the first row (0).
For each element in the current row:
Iterate from the first column (1) to the last column (m).
For each column element, iterate from 2 * j to m (inclusive) and update dp[i][j] by adding dp[i + 1][k].

4. Counting Sequences:
The final result is the sum of all elements in the first row (dp[0]).

5. Return Result:
Return the total count as the result.

*/
//solution

class Solution {
public:
    int numberSequence(int m, int n) {
        // Create a 2D vector 'dp' of size n x (m + 1) and initialize all elements to 0.
        vector<vector<int>> dp(n, vector<int>(m + 1, 0));

        // Initialize the last row (n-1) with 1, indicating that there is only one way to reach each element in the last row.
        for (int i = 1; i < m + 1; i++)
            dp[n - 1][i] = 1;

        // Iterate from the second last row (n - 2) to the first row (0).
        for (int i = n - 2; i > -1; i--) {
            // Iterate from the first column (1) to the last column (m).
            for (int j = 1; j < m + 1; j++) {
                // Iterate from 2 * j to m (inclusive) and update dp[i][j] by adding dp[i + 1][k].
                for (int k = 2 * j; k < m + 1; k++)
                    dp[i][j] += dp[i + 1][k];
            }
        }

        // Return the sum of all elements in the first row (row 0).
        return accumulate(dp[0].begin(), dp[0].end(), 0);
    }
};

