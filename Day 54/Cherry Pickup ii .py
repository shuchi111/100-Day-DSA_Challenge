'''
Algorithm: Cherry Pickup

Input:
grid: A 2D grid representing the cherry distribution.
Initialize Variables:
a: Number of rows in the grid.
b: Number of columns in the grid.
Define Recursive Function:
Define a recursive function dp(i, j, k) to represent the maximum number of cherries that can be picked starting from positions (i, j) and (i, k) for the first and second robots, respectively.

Base Cases:
If j and k are not within valid bounds, return negative infinity (-inf) as this path is not valid.
If i reaches the bottom of the grid, return 0, indicating that no more cherries can be picked.

Calculate Cherries at Current Positions:
Calculate the cherries picked at the current positions: grid[i][j] + (j != k) * grid[i][k]. If the robots are in different columns, add the cherries from both positions.

Recursive Calls:
For each possible move of the robots, iterate over the columns (y, z) where y represents the next column for the first robot, and z represents the next column for the second robot.
Use recursion to explore all possible moves from the current position and return the maximum number of cherries picked.

Memoization:
Memoize the results using the lru_cache decorator to avoid redundant calculations and improve efficiency.

Return Result:
Return the result of the initial call dp(0, 0, b-1), which represents the maximum number of cherries picked starting from the top-left and top-right corners.



Approach:

The problem is approached using dynamic programming with recursion and memoization.
The recursive function explores all possible moves of two robots simultaneously, considering the cherries picked at each position.
Memoization is employed to avoid redundant calculations and improve the overall efficiency of the solution.
The maximum number of cherries picked is calculated by starting from the top-left and top-right corners and making optimal moves at each step.

'''


class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        a=len(grid)
        b=len(grid[0])
        @lru_cache(None)
        def dp(i,j,k):
            if not 0<=j<=k<b:
                return -inf
            if i==a:
                return 0
            ans=grid[i][j]+(j!=k)*grid[i][k]
            return ans+max(dp(i+1,y,z) for y in (j-1,j,j+1) for z in (k-1,k,k+1))
        return dp(0,0,b-1) 
