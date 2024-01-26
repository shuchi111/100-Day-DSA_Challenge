#576. Out of Boundary Paths
"""
1. Define a DFS function dfs(i, j, k) to calculate the number of paths starting from (i, j) with k moves left:
   - If k < 0, return 0.
   - If (i, j) is out of bounds, return 1.
   - Initialize total to 0.
   - Iterate over possible moves (up, down, left, right):
      - Increment total by dfs(x, y, k-1) for each move (x, y).
   - Return total % (10^9 + 7).

2. In the main function findPaths(m, n, maxMove, startRow, startColumn):
   - Call dfs(startRow, startColumn, maxMove).
   - Return the result.

"""
class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        
       
        def dfs(i, j, k):
            if k < 0:
                return 0
            if i < 0 or i >= m or j < 0 or j >= n:
                return 1
            total = 0
            for x, y in [[i+1, j], [i-1, j], [i, j+1], [i, j-1]]:
                total += dfs(x, y, k-1)
            return total % (10**9 + 7)

        return dfs(startRow, startColumn, maxMove)
