# Equal row and column
"""
Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
Output: 1
Explanation: There is 1 equal row and column pair:
- (Row 2, Column 1): [2,7,7]




Algorithm explanation:

1.The outer loop iterates through each row (i) in the grid.
2. The middle loop iterates through the indices of elements in the current row.
3. The inner loop iterates through each row (k) to extract elements from the same column and appends them to the temporary list t.
4. After constructing t, it checks if the current row (i) is equal to t.
5. If the rows are equal, increment the counter (c).
6. Finally, return the count of equal pairs (c)
"""
class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        t = []  # temporary list to store columns
        c = 0   # counter for equal pairs
        
        # Iterate over each row in the grid
        for i in grid:
            # Iterate over indices of elements in the row
            for j in range(len(i)):
                t = []  # reset the temporary list for each column
                # Iterate over each row to get the elements in the same column
                for k in grid:
                    t.append(k[j])  # append the j-th element of each row to t
                
                # Check if the current row (i) is equal to the elements in the same column (t)
                if i == t:
                    c += 1  # increment the counter if the rows are equal
        
        return c  # return the count of equal pairs

