// Leetcode 75
// 1768. Merge Strings Alternately 

/*
Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s



Approach-

1. Input: 2D grid `grid`.
2. Initialize: 
   - `m, n = len(grid), len(grid[0])`
   - `row_ones = [0] * m`
   - `col_ones = [0] * n`
3. Count Ones in Each Row and Column:
   - For each element in the grid:
     - Update `row_ones[i]` and `col_ones[j]` based on the count of ones in each row and column.
4. Calculate Modified Grid:
   - For each element in the grid:
     - Update each element using the formula `2 * (row_ones[i] + col_ones[j]) - m - n`.
5. Output: Return the modified grid.


*/


class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size(),m = word2.size();
        int i=0,j=0;
        string ans = "";
        while(i<n && j<m)
        {
            ans+=word1[i++];
            ans+=word2[j++];
        }
        while(i<n)
        {
            ans+=word1[i++];
        }
        while(j<m)
        {
            ans+=word2[j++];
        }
        return ans;
    }
};