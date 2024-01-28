#1074. Number of Submatrices That Sum to Target
class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        rows, cols = len(matrix), len(matrix[0])
        # Compute the prefix sum for each row
        for row in matrix:
            for j in range(1, cols):
                row[j] += row[j - 1]

        result = 0

        # Iterate over all possible pairs of columns
        for i in range(cols):
            for j in range(i, cols):
                # Use a hashmap to store the prefix sum frequencies
                prefix_sum_count = {0: 1}
                current_sum = 0

                # Iterate over all rows and compute the current submatrix sum
                for k in range(rows):
                    if i == 0:
                        current_sum += matrix[k][j]
                    else:
                        current_sum += matrix[k][j] - matrix[k][i - 1]

                    # Check if there is a submatrix with the target sum
                    if current_sum - target in prefix_sum_count:
                        result += prefix_sum_count[current_sum - target]

                    # Update the prefix sum count
                    prefix_sum_count[current_sum] = prefix_sum_count.get(current_sum, 0) + 1

        return result


'''
Algorithm:

Calculate the prefix sum for each row in the matrix.

Initialize result to 0.

Iterate over all pairs of columns (i and j):

Use a hashmap (prefix_sum_count) to store the count of prefix sums.
Initialize current_sum to 0.
Iterate over all rows (k):

Update current_sum based on the values in the matrix.
Check if there is a submatrix with the target sum in the prefix_sum_count hashmap:

If found, increment result by the count of such submatrices.
Update the prefix_sum_count hashmap with the current_sum and its count.

Return the final result.


Example 2:

Input: matrix = [[1,-1],[-1,1]], target = 0
Output: 5
Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.

'''
