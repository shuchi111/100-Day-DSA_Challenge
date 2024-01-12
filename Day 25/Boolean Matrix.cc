//Boolean Matrix
/*

Input:
matrix[][] = {{1, 0},
              {0, 0}}
Output: 
1 1
1 0 
Explanation:
Only cell that has 1 is at (0,0) so all 
cells in row 0 are modified to 1 and all 
cells in column 0 are modified to 1.


Algorithm:

To modify the matrix such that if a matrix cell matrix[i][j] is 1, then all the cells in its ith row and jth column will become 1, we can follow these steps:

1. Traverse the matrix and create a vector v to store the coordinates of all cells with value 1.
2. Iterate through the vector v, and for each pair (i, j) in v, set all elements in the ith row and jth column to 1.
3. The modified matrix now satisfies the required condition.


*/

//Solution
class Solution {
public:
    void booleanMatrix(vector<vector<int> > &matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<pair<int, int>> v;

        // Step 1: Traverse matrix and store coordinates of cells with value 1
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == 1) {
                    v.push_back({i, j});
                }
            }
        }

        // Step 2: Set elements in the ith row and jth column to 1 for each (i, j) in vector v
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < c; j++) {
                matrix[v[i].first][j] = 1;
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < v.size(); j++) {
                matrix[i][v[j].second] = 1;
            }
        }
    }
};
